#pragma once

#include <QVariant>

#include "CText.h"

class CodeArgument
{
public: // types
    typedef QList<CodeArgument> List;

public: // ctors
    CodeArgument(const QVariant &var);
    CodeArgument(const QVariant &var, const CText &argName, const CText &typeName);

public: // const

public: // non-const

public: // debug
    QString toDebugString() const;

private:
    QVariant mValue;
    CText mArgumentName;
    CText mTypeMetaName;
    QMetaType mMetaType;

public: // QMetaType
    CodeArgument() = default;
    ~CodeArgument() = default;
    CodeArgument(const CodeArgument &) = default;
    CodeArgument &operator=(const CodeArgument &) = default;
};

Q_DECLARE_METATYPE(CodeArgument);



