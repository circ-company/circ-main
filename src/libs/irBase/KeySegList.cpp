#include "KeySegList.h"

KeySegList::KeySegList() { set(); }
KeySegList::KeySegList(const char *pch) { set(pch); }
KeySegList::KeySegList(const AText &at) { set(at); }
KeySegList::KeySegList(const QString &s) { set(s); }
KeySegList::KeySegList(const QWORD aQWord) { set(aQWord); }
KeySegList::KeySegList(const QList<KeySeg> &other) { set(other); }

QString KeySegList::toString() const
{
    return toString(QString(hinge()));
}

QString KeySegList::toString(const QString &separator) const
{
    QString result;
    KeySegList tCopy = it();
    if ( ! tCopy.isEmpty())     result = tCopy.takeFirst();
    while ( ! tCopy.isEmpty())  result += separator + QString(tCopy.takeFirst());
    return result;
}

QStringList KeySegList::toStringList() const
{
    QStringList result;
    foreach (const KeySeg cSeg, it())
        result << cSeg.toString();
    return result;
}

KeySeg KeySegList::toSeg() const
{
    return KeySeg(toString().remove(QChar(hinge()), Qt::CaseInsensitive));
}

KeySegList KeySegList::add(const KeySeg &aSeg) const
{
    KeySegList result = it();
    result.append(aSeg);
    return result;
}

void KeySegList::set(const AText &at)
{
    clear();
    foreach (const AText cAT, at.split(hinge()))
        append(KeySeg(cAT));
}

void KeySegList::set(const QWORD aQWord)
{
    set(QString("%1/%2/%3/%4")
            .arg(aQWord >> 48, 8, 16, u'0')
            .arg(aQWord & 0x0000FFFF00000000 >> 32, 8, 16, u'0')
            .arg(aQWord & 0x00000000FFFF0000 >> 16, 8, 16, u'0')
            .arg(aQWord & 0x000000000000FFFF, 8, 16, u'0'));
}

void KeySegList::set(const QList<KeySeg> &other)
{
    clear();
    foreach (const KeySeg cSeg, other)
        append(cSeg);
}
