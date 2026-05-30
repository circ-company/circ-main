#include "FSTextList.h"

FSTextList::FSTextList() {;}
FSTextList::FSTextList(const QByteArrayList &other) { set(other); }
FSTextList::FSTextList(const FSText::List &other) { *this = other; }

FSText FSTextList::join(const FSText fstx) const
{
    FSTextList tList = *this;
    FSText result = isEmpty() ? AText() : tList.takeFirst();
    while ( ! tList.isEmpty())
    {
        result += fstx;
        result += tList.takeFirst();
    }
    return result;
}

QStringList FSTextList::toStringList() const
{
    static QStringList result;
    result.clear();
    foreach (const FSText cText, it())
        result << cText();
    return result;
}

void FSTextList::set(const QByteArrayList bal)
{
    clear();
    foreach (const QByteArray cBA, bal)
        append(FSText(cBA));
}

void FSTextList::set(const QStringList qsl)
{
    clear();
    foreach (const QString cQS, qsl)
        append(FSText(cQS));
}

void FSTextList::prependEach(const FSText &fstx)
{
    FSTextList tNewList;
    foreach (const FSText cText, it())
        tNewList.append(fstx + cText);
    it() = tNewList;
}
