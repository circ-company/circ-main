#pragma once

#include <QMetaType>
#include <QString>
#include <QVariant>

#include "AText.h"
#include "CText.h"
#include "List.h"

class ArgumentInfo
{
public: // types
    typedef ListT<ArgumentInfo> List;

public: // ctors
    ArgumentInfo(const CText aName);
    ArgumentInfo(const CText aName, const QMetaType aMetaType);
    ArgumentInfo(const char * aPCH, const QVariant aValue);
    ArgumentInfo(const CText aName, const QVariant aValue);
    ArgumentInfo(const CText aName,
                 const AText &aValueText, const QVariant &aValue);
    ArgumentInfo(const CText aName,
                 const AText &aValueText, const QVariant &aValue,
                 const AText &aDefaultText, const QVariant aDefault);

public: // const
    bool isNull() const;
    CText name() const;
    QMetaType metaType() const;
    QVariant value() const;
    QVariant defaultValue() const;
    QString description() const;

public: // non-const
    void clear();
    void name(const CText &aName);
    void metaType(const QMetaType aMetaType);
    void metaType(const int aTypeId);
    void metaType(const CText &aTypeName);
    void value(const QVariant &aValue);
    void defaultValue(const QVariant &aValue);
    void description(const QString &aDescription);

public: // pointers

public: // debug
    QString toDebugString() const;

private:
    CText mName;
    QMetaType mMetaType;
    AText mValueText;
    QVariant mValue;
    AText mDefaultText;
    QVariant mDefault;
    QString mDescription;

public: // QMetaType
    ArgumentInfo() = default;
    ~ArgumentInfo() = default;
    ArgumentInfo(const ArgumentInfo &) = default;
    ArgumentInfo &operator=(const ArgumentInfo &) = default;
    ArgumentInfo & it() { return *this; }
    const ArgumentInfo & it() const { return *this; }
};

inline bool ArgumentInfo::isNull() const { return name().isEmpty() || value().isNull(); }
inline CText ArgumentInfo::name() const { return mName; }
inline QMetaType ArgumentInfo::metaType() const { return mMetaType; }
inline QVariant ArgumentInfo::value() const { return mValue; }
inline QVariant ArgumentInfo::defaultValue() const { return mDefault; }
inline QString ArgumentInfo::description() const { return mDescription; }
inline void ArgumentInfo::name(const CText &aName) { mName = aName; }
inline void ArgumentInfo::metaType(const QMetaType aMetaType) { mMetaType = aMetaType; }
inline void ArgumentInfo::metaType(const int aTypeId) { mMetaType = QMetaType(aTypeId); }
inline void ArgumentInfo::metaType(const CText &aTypeName) { mMetaType = QMetaType::fromName(aTypeName); }
inline void ArgumentInfo::value(const QVariant &aValue) { mValue = aValue; }
inline void ArgumentInfo::defaultValue(const QVariant &aValue) { mDefault = aValue; }
inline void ArgumentInfo::description(const QString &aDescription) { mDescription = aDescription; }

Q_DECLARE_METATYPE(ArgumentInfo);
