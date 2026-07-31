#include "KeySegList.h"

KeySegList::KeySegList() { set(); }
KeySegList::KeySegList(const char *pch) { set(pch); }
KeySegList::KeySegList(const AText &at) { set(at); }
KeySegList::KeySegList(const QString &s) { set(s); }
KeySegList::KeySegList(const ListT<KeySeg> &other) { set(other); }

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

void KeySegList::set(const AText &at)
{
    clear();
    foreach (const AText cAT, at.split(hinge()))
        append(KeySeg(cAT));
}

void KeySegList::set(const ListT<KeySeg> &other)
{
    clear();
    foreach (const KeySeg cSeg, other)
        append(cSeg);
}
