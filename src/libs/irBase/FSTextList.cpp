#include "FSTextList.h"

FSTextList::FSTextList() {;}
FSTextList::FSTextList(const QByteArrayList &aQBAL) { set(aQBAL); }
FSTextList::FSTextList(const QStringList &aQSL) { set(aQSL); }
FSTextList::FSTextList(const ATextList &other) { set(other); }
FSTextList::FSTextList(const QList<FSText> &other) { set(other); }

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

void FSTextList::set(const AText::List atxl)
{
    clear();
    foreach (const AText cAtx, atxl)
        append(FSText(cAtx));
}

void FSTextList::set(const QList<FSText> fstxl)
{
    clear();
    foreach (const FSText cFStx, fstxl)
        append(cFStx);
}

void FSTextList::prependEach(const FSText &fstx)
{
    FSTextList tNewList;
    foreach (const FSText cText, it())
        tNewList.append(fstx + cText);
    it() = tNewList;
}
