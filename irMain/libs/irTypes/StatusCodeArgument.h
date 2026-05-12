#pragma once

#include <QVariant>

#include "CText.h"

class StatusCodeArgument
{
public: // types
    typedef QList<StatusCodeArgument> List;

public: // ctors
    StatusCodeArgument(const QVariant &var);
    StatusCodeArgument(const QVariant &var, const CText &argName, const CText &typeName);

public: // const

public: // non-const

private:
    QVariant mValue;
    CText mArgumentName;
    CText mTypeMetaName;
    QMetaType mMetaType;

public: // QMetaType
    StatusCodeArgument() = default;
    ~StatusCodeArgument() = default;
    StatusCodeArgument(const StatusCodeArgument &) = default;
    StatusCodeArgument &operator=(const StatusCodeArgument &) = default;
};

Q_DECLARE_METATYPE(StatusCodeArgument);



