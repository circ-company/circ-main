#pragma once

#include <QMetaType>
#include <QVariant>
#include <QVariantList>

#include "AText.h"
#include "StatusLevel.h"

class Status
{
public: // types

public: // ctors
    Status(const StatusLevel aLevel);
    Status(const StatusLevel aLevel, const AText &aMsg);

public: // const
    bool isNull() const;
    bool isError() const;
    bool notError() const;
    StatusLevel level() const;
    AText message() const;
    QString toString() const;

public: // non-const
    void level(const StatusLevel aLevel);
    void message(const AText &aMsg);
    void set(const StatusLevel aLevel, const AText &aMsg);
    void set(const StatusLevel aLevel, const AText &aFmt,
             const QVariantList &aVars);
    void set(const StatusLevel aLevel, const AText &aFmt,
             const QVariant &aVar1, const QVariant &aVar2=QVariant(),
             const QVariant &aVar3=QVariant(), const QVariant &aVar4=QVariant());

public: // pointers

public: // debug

private:
    StatusLevel mLevel=StatusLevel::$null;
    AText mMessage;

public: // QMetaType
    Status() = default;
    ~Status() = default;
    Status(const Status &) = default;
    Status &operator=(const Status &) = default;
    Status & it() { return *this; }
    const Status & it() const { return *this; }
};

Q_DECLARE_METATYPE(Status);

inline bool Status::isNull() const { return level().isNull(); }
inline bool Status::isError() const { return level().isError(); }
inline bool Status::notError() const { return ! isError(); }
inline StatusLevel Status::level() const { return mLevel; }
inline AText Status::message() const { return mMessage; }
inline void Status::level(const StatusLevel aLevel) { mLevel = aLevel; }
inline void Status::message(const AText &aMsg) { mMessage = aMsg; }

