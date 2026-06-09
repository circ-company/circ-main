#include "CText.h"

#include <ctype.h>

char CText::smHingeChar = ' ';

CText::CText() {;}
CText::CText(const char *pch) : AText(pch) {;}
CText::CText(const QByteArray &ba) : AText(ba) {;}
CText::CText(const QByteArray &ba, const QChar repl) : AText(ba, repl) {;}
CText::CText(const QString &s) : AText(s) {;}
// CText::CText(const unsigned int u, const BYTE base) : AText(u, base) {;}

bool CText::isValidFirst(const char ch) const
{
    return isupper(ch) || islower(ch);
}

bool CText::isValidChar(const char ch) const
{
    return isupper(ch) || islower(ch) || isdigit(ch);
}
