#include "ATextList.h"

#include <QString>

//#include "Types.h"

ATextList::ATextList(const AText::List &other) : AText::List(other) {;}

ATextList::ATextList(const QByteArrayList &other)
{
    foreach (const QByteArray cBA, other)
        append(AText(cBA));
}

ATextList::ATextList(const QStringList &other)
{
    foreach (const QString cS, other)
        append(AText(cS));
}

ATextList &ATextList::operator =(const AText::List &other)
{
    foreach (const AText cAT, other)
        append(cAT);
    return it();
}


AText ATextList::join(const AText atx) const
{
    ATextList tList = *this;
    AText result = isEmpty() ? AText() : tList.takeFirst();
    while ( ! tList.isEmpty())
    {
        result += atx;
        result += tList.takeFirst();
    }
    return result;
}

ATextList::PairList ATextList::split(const char ch) const

{
    ATextList::PairList result;
    foreach (const AText cATextIn, it())
    {
        const AText::Pair cPair = cATextIn.keyValue(ch);
        result.append(cPair);
    }
    return result;
}

// ---------------------- static -----------------------

ATextList ATextList::hexDump(const QByteArray &ba)
{
    ATextList result;
    Index ix = 0;
    while ((ba.length() - ix) > 16)
    {
        result << hexDumpFullLine(ix, ba);
        ix += 16;
    }
    if (ix < ba.length())
    {
        result << hexDumpPartLine(ix, ba);
    }
    return result;
}

ATextList ATextList::toList(const PairList atxlpr, const char assign)
{
    ATextList result;
    foreach (const AText::Pair cAtxp, atxlpr)
    {
        const AText cAtx = cAtxp.first + assign + cAtxp.second;
        result << cAtx;
    }
    return result;
}


ATextList ATextList::toList(const PairMMap atxlMm, const char assign)
{
    ATextList result;
    QMultiMapIterator<AText, AText> mmit(atxlMm);
    while (mmit.hasNext())
    {
        mmit.next();
        const AText cKey = mmit.key();
        const AText cVal = mmit.value();
        const AText cAtx = cKey + assign + cVal;
        result << cAtx;
    }
    return result;
}

AText ATextList::hexDumpFullLine(const Index ix, const QByteArray &ba)
{
    AText tChars(ba.mid(ix, 16), u'.');
    AText result = QString("%1 0x%2 %3 %4 %5 %6").arg(ix, 5, 10, u'0')
                        .arg(ba.mid(ix+ 0, 4).toHex().toUpper())
                        .arg(ba.mid(ix+ 4, 4).toHex().toUpper())
                        .arg(ba.mid(ix+ 8, 4).toHex().toUpper())
                        .arg(ba.mid(ix+12, 4).toHex().toUpper())
                        .arg((tChars.takeFirst(16))());
    return result;
}

AText ATextList::hexDumpPartLine(const Index ix, const QByteArray &ba)
{
    AText result = QString("%1 0x").arg(ix, 5, 10, u'0');
    Count k = ba.length() - ix;
    Index ix2 = 0;
    QByteArray tBytes = ba.mid(ix);
    AText tChars(tBytes, u'.');
    while (k > 0)
    {

        result += tBytes.mid(ix + ix2, 1).toHex().toUpper();
        if (++ix2 % 4) result += ' ';
        --k;
    }
    result += AText(42 - result.length(), ' ');
    result += tChars;
    return result;
}
