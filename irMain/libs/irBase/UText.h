#pragma once

#include <QString>

class UText : public QString
{
public: //ctors
    UText();
    UText(const char * pch);
    UText(const QByteArray &ba);
    UText(const QString &other);

};
