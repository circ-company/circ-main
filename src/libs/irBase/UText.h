#pragma once

#include <QString>

#include <QMetaType>

#include "List.h"

class UText : public QString
{
public: // types
    typedef ListT<UText> List;

public: // ctors
    UText(const char * pch);
    UText(const QByteArray &ba);
    UText(const QString &other);

public: // const

public: // non-const

public: // pointers
    const UText & it() const { return *this; }
    UText & it() { return *this; }

public: // QMetaType
    UText() = default;
    ~UText() = default;
    UText(const UText &) = default;
    UText &operator=(const UText &) = default;
};

Q_DECLARE_METATYPE(UText);
