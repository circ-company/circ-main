#include "Key.h"

#include <QList>
#include <QStringList>

#include "Types.h"
#include "Uid.h"

bool Key::startsWith(const Key &start) const
{
    for (Index ix = 0; ix < start.count(); ++ix)
        if ( ! isValidIndex(ix) || at(ix) != start.at(ix))
            return false;
    return true;
}

QVariant Key::toVariant() const
{
    QVariant result;
    result.setValue<Key>(it());
    return result;
}

QWORD Key::hash64() const
{
    union
    {
        QWORD qw;
        WORD w[4];
    } tUnion;
    tUnion.qw = 0uLL;
    KeySegList tSegments = it();
    Index tWordIndex = countof(tUnion.w) - 1;
    while (tSegments.notEmpty())
    {
        const KeySeg tSeg = tSegments.takeLast();
        const WORD tHash16 = tSeg.hash16();
        tUnion.w[tWordIndex] ^= tHash16;
        if (tWordIndex) --tWordIndex;
    }
    return tUnion.qw;
}

Uid Key::toUid() const
{
    Uid result(Uid::VarFromKey);
    KeySegList tSegments = it();
    // TODO Use QRandom64
    DWORD segA = random();
    WORD  segB = random();
    WORD  segC = random();
    WORD  segD = random();
    QWORD segE = QWORD(random() << 32) | QWORD(random());
    if (tSegments.notEmpty()) segA = qHash(tSegments.takeFirst());
    if (tSegments.notEmpty()) segB = qHash(tSegments.takeFirst());
    if (tSegments.notEmpty()) segC = qHash(tSegments.takeFirst());
    if (tSegments.notEmpty()) segD = qHash(tSegments.takeFirst());
    while (tSegments.notEmpty()) segE ^= qHash(tSegments.takeFirst());
    return Uid(segA, segB, segC, segD, segE);
}

Key Key::operator + (const KeySeg &aSeg) const
{
    return Key(it() + aSeg);
}

// global
Key operator+(const Key &aKey, KeySeg &aSeg)
{
    return aKey.add(aSeg);
}

// static
Key Key::fromName(const QString aName)
{
    Key result;
    QStringList tStringList = aName.simplified().split(' ');
    while ( ! tStringList.isEmpty())
    {
        const QString cStr = tStringList.takeFirst();
        const KeySeg cSeg(cStr);
        if ( ! cSeg.isEmpty())
            result.add(cSeg);
    }
    return result;
}

