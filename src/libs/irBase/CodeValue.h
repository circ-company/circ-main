#pragma once

#include <QString>
#include <QVariant>

#include "CText.h"
#include "List.h"

class CodeValue
{
public: // types
    typedef ListT<CodeValue> List;

public: // ctors
    CodeValue(const QVariant &var, const CText &argName,
              const QVariant &def=QVariant(), const AText &defName=AText());
    CodeValue(const QVariant &var, const char *argPch,
              const QVariant &def=QVariant(), const char *defPch=0);

public: // const
    bool isNull() const;
    QVariant value() const;
    QString string() const;
    CText name() const;
    CText metaName() const;
    QMetaType metaType() const;
    int metaTypeId() const;
    QVariant defValue() const;
    QString defString() const;
    CText defName() const;
    CText defMetaName() const;
    QMetaType defMetaType() const;

public: // non-const

public: // debug
    QString toDebugString() const;

private:
    QVariant mValue;
    CText mName;
    QMetaType mMetaType;
    QVariant mDefValue;
    AText mDefName;
    AText mDescription;
    QMetaType mDefMetaType;


public: // QMetaType
    CodeValue it() const { return *this; }
    CodeValue & it() { return *this; }
    CodeValue() = default;
    ~CodeValue() = default;
    CodeValue(const CodeValue &) = default;
    CodeValue &operator=(const CodeValue &) = default;
};

Q_DECLARE_METATYPE(CodeValue);

inline bool CodeValue::isNull() const { return QMetaType::UnknownType == metaTypeId(); }
inline QVariant CodeValue::value() const { return mValue; }
inline QString CodeValue::string() const { return value().toString(); }
inline CText CodeValue::name() const { return mName; }
inline CText CodeValue::metaName() const { return metaType().name(); }
inline QMetaType CodeValue::metaType() const { return mMetaType; }
inline int CodeValue::metaTypeId() const { return metaType().id(); }
inline QVariant CodeValue::defValue() const { return mDefValue; }
inline QString CodeValue::defString() const { return defValue().toString(); }
inline CText CodeValue::defName() const { return mDefName; }
inline CText CodeValue::defMetaName() const { return defMetaType().name(); }
inline QMetaType CodeValue::defMetaType() const { return defMetaType(); }

