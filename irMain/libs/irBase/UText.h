#pragma once

#include <QString>

#include <QList>

class UText : public QString
{
public: //types
    typedef QList<UText> List;

public: //ctors
    UText();
    UText(const char * pch);
    UText(const QByteArray &ba);
    UText(const QString &other);

};
