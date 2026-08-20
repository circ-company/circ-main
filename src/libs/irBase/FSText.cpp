#include "FSText.h"

#include <ctype.h>

#include <QByteArrayList>


char FSText::smHingeChar = '/';

FSText::FSText() {;}
FSText::FSText(const char *pch) : AText(pch) {;}
FSText::FSText(const char *pch, const QChar repl, const bool aReplaceSpace) : AText(pch, repl)
{ if (aReplaceSpace) replace(' ', repl.cell()); }
FSText::FSText(const char ch) : AText(ch) {;}
FSText::FSText(const QByteArray &ba) : AText(ba) {;}
FSText::FSText(const QString &s) : AText(s) {;}

FSText::List FSText::split(const char aCh) const
{
    FSText::List result;
    const QByteArray cQBA = toQBA();
    const QByteArrayList cBAL = cQBA.split(aCh);
    foreach (const QByteArray cBA, cBAL)
        result.append(FSText(cBA));
    return result;
}

bool FSText::isValidFirst(const char ch) const
{
    return isValidChar(ch);
}

bool FSText::isValidChar(const char ch) const
{
    return isupper(ch) || islower(ch) || isdigit(ch) || isspace(ch)
           || AText("*?-./_\\:").contains(ch);
}
