#pragma once

#include <QString>
#include <QVariant>

#include "CText.h"

class CodeValue
{
public: // types
    typedef QList<CodeValue> List;

public: // ctors
    CodeValue(const QVariant &var, const CText &argName);
    CodeValue(const QVariant &var, const char argPch[]);

public: // const
    QVariant value() const;
    QString string() const;
    CText name() const;
    CText metaName() const;
    QMetaType metaType() const;

public: // non-const

public: // debug
    QString toDebugString() const;

private:
    QVariant mValue;
    CText mName;
    QMetaType mMetaType;

public: // QMetaType
    CodeValue it() const { return *this; }
    CodeValue & it() { return *this; }
    CodeValue() = default;
    ~CodeValue() = default;
    CodeValue(const CodeValue &) = default;
    CodeValue &operator=(const CodeValue &) = default;
};

Q_DECLARE_METATYPE(CodeValue);

inline QVariant CodeValue::value() const { return mValue; }
inline QString CodeValue::string() const { return value().toString(); }
inline CText CodeValue::name() const { return mName; }
inline CText CodeValue::metaName() const { return metaType().name(); }
inline QMetaType CodeValue::metaType() const { return mMetaType; }




