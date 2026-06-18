#include "KeySegList.h"

QString KeySegList::toString() const
{
#if 1
    return toString(QString(hinge()));
#else
    QString result;
    KeySegList tCopy = it();
    if ( ! tCopy.isEmpty())     result = tCopy.takeFirst();
    while ( ! tCopy.isEmpty())  result += hinge() + tCopy.takeFirst();
    return result;
#endif
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
