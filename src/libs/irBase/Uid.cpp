#include "Uid.h"

#include <QtEndian>
#include <QNetworkInterface>
#include <QRandomGenerator>

#include "../../../doctest/doctest/doctest.h"

#include "KeySeg.h"
#include "NanosecondTime.h"
#include "XText.h"

//DWORD smMacAddress24 = 0;
QDateTime smTimestamp;

Uid::Uid(const bool random) { if (random) randomize(); else nilify(); }
Uid::Uid(const Variant var) { generate(var); }
Uid::Uid(const Version ver, const QWORD &macOverride, const QDateTime &tstampOverride)
    { generateTimeMac(ver, macOverride, tstampOverride); }

Uid::Uid(const Version ver, const AText text, const Uid &ns)
{
    switch(ver)
    {
    case VerTextMd5:    QUuid::createUuidV3(ns, text);      break;
    case VerTextSha:    QUuid::createUuidV5(ns, text);      break;
    default:            qWarning() << "Invalid Version";    break;
    };
}

Uid::Uid(const DWORD segA, const WORD segB, const WORD segC, const WORD segD,
         const QWORD segE48, const Version ver, const Variant var)
    { set(segA, segB, segC, segD, segE48, ver, var); }


TEST_CASE("eirCore/Uid ctors")
{
    Uid uidNull;
    Uid uidRandom(true);
    Uid uidNil(false);
    Uid uidRef = Uid::reference();

    CHECK( ! uidNull.isNil());
    CHECK(uidNull.isNull());
    CHECK( ! uidRandom.isNil());
    CHECK(uidNil.isNil());
    CHECK( ! uidRef.isNil());
    CHECK( ! uidNil.isNull());
    CHECK( ! uidRandom.isNull());
    CHECK( ! uidRef.isNull());

    CHECK(0x01234567 == uidRef.segment(Uid::SegmentA));
    CHECK(0x89AB == uidRef.segment(Uid::SegmentB));
    CHECK(0x0DEF == uidRef.segment(Uid::SegmentC));
    CHECK(0x0123 == uidRef.segment(Uid::SegmentD));
//    CHECK(0x0000456789ABCDEFUL == uidRef.segment(Uid::SegmentE));
}

bool Uid::isNull() const
{
    return scmNullValue == mUnion.data128[0];
}

bool Uid::isNil() const
{
    return 0 == mUnion.data128[0];
}

bool Uid::equals(const Uid &rhs) const
{
#ifdef Q_CC_MSVC
    return hi() == rhs.hi() && lo() == rhs.lo();
#else
    return oword() == rhs.oword();
#endif
}

bool Uid::less(const Uid &rhs) const
{
#ifdef Q_CC_MSVC
    return (hi() == rhs.hi()) ? (lo() < rhs.lo()) : (hi() < rhs.hi());
#else
    return oword() < rhs.oword();
#endif
}

QString Uid::toString(const QUuid::StringFormat mode) const
{
    return uuid().toString(mode);
}

QWORD Uid::segment(const Segment uidseg) const
{
    QWORD result = 0;
    if (isValidSegment(uidseg))
    {
        OWORD tOW = mUnion.data128[0];
        tOW &= segmentMask(uidseg);
        tOW >>= segmentBitOffset(uidseg);
        result = QWORD(tOW);
    }
    return result;
}

Key Uid::toKey(const KeySeg &prefix) const
{
    Key result = prefix;
    result.append(toString(QUuid::WithoutBraces).replace('-', Key::hinge()));
    return result;
}

QString Uid::tail() const
{
    return toString().right(14);
}

QUuid Uid::uuid() const
{
    return QUuid(mUnion);
}

QWORD Uid::hi() const
{
    return mUnion.data64[0];
}

QWORD Uid::lo() const
{
    return mUnion.data64[1];
}

#ifndef Q_CC_MSVC
OWORD Uid::oword() const
{
    return mUnion.data128[0];
}

Uid::Version Uid::ver() const
{
    return Version(segment(SegmentC) >> 12);
}

Nanoseconds Uid::nsecs() const
{
    Nanoseconds result = -1;
    DWORD tLow = 0, tMid = 0, tHi = 0;
    switch (ver())
    {
    case Uid::VerGTimeseqNode1:
        tLow = segment(SegmentA);
        tMid = segment(SegmentB);
        tHi  = segment(SegmentC);
        result += tHi  << (segmentBitLength(SegmentA) + segmentBitLength(SegmentB));
        result += tMid <<  segmentBitLength(SegmentA);
        result += tLow;
        result *= 100;
        result += NanosecondTime::gregorianOffset();
        break;

    case Uid::VerGTimeseqNode6:
        tLow = segment(SegmentC);
        tMid = segment(SegmentB);
        tHi  = segment(SegmentA);
        result += tHi  << (segmentBitLength(SegmentB) + segmentBitLength(SegmentC));
        result += tMid <<  segmentBitLength(SegmentC);
        result += tLow;
        result *= 100;
        result += NanosecondTime::gregorianOffset();
        break;

    case Uid::VerUTimeseqRandom:
        tHi  = segment(SegmentA);
        tLow = segment(SegmentB);
        result = ((tHi << 16) + tLow) * NanosecondTime::nanoFactor();
        break;

    default:
        // no time info in these versions
        break;
    }
    return result;
}
#endif

void Uid::hi(const QWORD qw)
{
    mUnion.data64[0] = qw;
}

void Uid::lo(const QWORD qw)
{
    mUnion.data64[1] = qw;
}

void Uid::set(const QUuid other)
{
    mUnion.data128[0] = other.toBytes(QSysInfo::BigEndian).data128[0];
}

void Uid::set(const Variant var)
{
    mUnion.data[8] &= 0x0F;
    mUnion.data[8] |= ((BYTE)var) << 4;
}

void Uid::set(const Version ver)
{
    set(VarDce);
    mUnion.data[6] &= 0x0F;
    mUnion.data[6] |= ((BYTE)ver) << 4;
}

void Uid::set(const Index bitOffset, const Count bitCount, const QWORD qw)
{
    OWORD tMask = (OWORD((1LL << bitCount) - 1)) << bitOffset;
    OWORD tValue = qw;
    mUnion.data128[0] = mUnion.data128[0] & ( ~ tMask);
    mUnion.data128[0] = mUnion.data128[0] | ((tValue << bitCount) & ( ~ tMask));
}

void Uid::set(const Segment seg, const QWORD qw)
{
    const Index cBitOffset = segmentBitOffset(seg);
    const Count cBitCount = segmentBitLength(seg);
    set(cBitOffset, cBitCount, qw);
}

void Uid::set(const DWORD segA, const WORD segB, const WORD segC,
              const WORD segD, const QWORD segE48, const Version ver, const Variant var)
{
    set(SegmentA, segA),
    set(SegmentB, segB),
    set(SegmentC, segC),
    set(SegmentD, segD),
    set(SegmentE, segE48 & 0x0000FFFFFFFFFFFFFFFFuLL);
    set(var);
    set(ver);
}

Uid Uid::generateFullRandom(const bool random)
{
    if (random)
        generateRandomV4();
    else
        nilify();
    return it();
}

Uid Uid::generate(const Variant var)
{
    Uid result;
    if (isVarNcs(var) || isVarGuid(var))
    {
        result.randomize();
        result.set(var);
    }
    return it() = result;
}

Uid Uid::generateTimeMac(const Version ver, const QWORD &macOverride, const QDateTime &tstampOverride)
{
    Uid result;
    const QWORD cMac = (macOverride ? macOverride : machineAddress());
    const Milliseconds cEms = (tstampOverride.isNull()
                                   ? QDateTime::currentDateTimeUtc()
                                   : tstampOverride).toMSecsSinceEpoch();
    static QWORD sSequence = 0;
    const QWORD cHalfQWord = ULONG_LONG_MAX >> 1;
    sSequence += (sSequence >= cHalfQWord) ? 1 : ( - cHalfQWord);
    const QWORD cTime60 = (cEms * 1000) + (sSequence % 1000);
    result.set(ver);
    switch (ver)
    {
    case VerGTimeseqNode1:
        result.set(SegmentA,  cTime60 & 0x00000000FFFFFFFF);
        result.set(SegmentB, (cTime60 & 0x0000FFFF00000000) >> 32);
        result.set(SegmentC, (cTime60 & 0x0FFF000000000000) >> 48);
        break;
    case VerGTimeseqNode6:
        result.set(SegmentA, (cTime60 & 0x00FFFFFFF0000000) >> 28);
        result.set(SegmentB, (cTime60 & 0x000000000FFFF000) >> 12);
        result.set(SegmentC,  cTime60 & 0x0000000000000FFF);
        break;
    default:
        break;
    }
    result.set(SegmentD,  (sSequence & 0x0FFF0000) >> 16);
    result.set(SegmentE, ((sSequence & 0x0000FFFF) << 24) | (cMac & 0x00FFFFFF));
    return result;
}

Uid Uid::generateRandomV4()
{
    Uid result; // null
    randomize();
    set(VerRandom);
    return result;
}

void Uid::nullify()
{
    mUnion.data128[0] = scmNullValue;
}

void Uid::nilify()
{
    mUnion.data128[0] = 0;
}

void Uid::maxify()
{
    nilify();
    mUnion.data128[0] = ~ mUnion.data128[0];
}

void Uid::randomize()
{
    lo(QRandomGenerator::global()->generate64());
    hi(QRandomGenerator::global()->generate64());
}

Uid Uid::reference()
{
#if 0
    Uid result("{01234567-89AB-CDEF-0123-4567890ABCDEF}");
#else
    Uid result(false); // nil
    result.set(VerCustom);
    result.set(SegmentA, 0x01234567);
    result.set(SegmentB, 0x89AB);
    result.set(SegmentC, 0xCDEF);
    result.set(SegmentD, 0x0123);
    result.set(SegmentE, 0x456789ABCDEF);
#endif
    return result;
}

DWORD Uid::machineAddress()
{
    DWORD result = 0;
    QNetworkInterface tNetIf = QNetworkInterface::interfaceFromIndex(2);
    XText tXTx = tNetIf.hardwareAddress();
    result = tXTx.toULong(nullptr, 16) & 0x00FFFFFF; // TODO fix me
//    qDebug() << Q_FUNC_INFO << tNetIf.name() << tXTx << Qt::hex << result;
    return result;
}

XText Uid::xtext(const Segment uidseg) const
{
    XText result;
    if (isValidSegment(uidseg))
    {
        const QWORD cQW = segment(uidseg);
        result.set(&cQW, segmentBitLength(uidseg) / 8);
    }
    return result;
}

bool Uid::isVarNcs(const Variant var)
{
    return var >= VarNcs && var <= VarNcs7;
}

bool Uid::isVarGuid(const Variant var)
{
    return var >= VarGuid && var <= VarGuid13;
}

bool Uid::isNull(const Segment uidseg)
{
    return $nullSegment == uidseg;
}

bool Uid::isValidSegment(const Segment uidseg)
{
    switch (uidseg)
    {
    case $nullSegment:          return false;

    case SegmentA:
    case SegmentB:
    case SegmentC:
    case SegmentD:
    case SegmentE:              return true;

    case SegmentVar:
    case SegmentVer:            return true;

    default:                    return false;
    }
}

unsigned Uid::segmentBitOffset(const Segment uidseg)
{
    unsigned result = 0;
    if (isValidSegment(uidseg))
        result = (uidseg & 0xFF00) >> 8;
    return result;
}

Count Uid::segmentBitLength(const Segment uidseg)
{
    int result = -1;
    if (isValidSegment(uidseg))
        result = uidseg & 0x00FF;
    return result;
}

OWORD Uid::segmentMask(const Segment uidseg)
{
    OWORD result = -1;
    if (isValidSegment(uidseg))
    {
        result = (1LL << segmentBitLength(uidseg)) - 1;
        result <<= segmentBitOffset(uidseg);
    }
    return result;
}
/*
DWORD Uid::macAddress()
{
    return (smMacAddress24 ? smMacAddress24 : machineAddress()) & 0x00FFFFFF;
}
*/
