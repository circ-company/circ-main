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
    StatusLevel level() const;
    AText message() const;
    QString toString() const;
    QVariant toVariant() const;
    operator QVariant () const;

public: // non-const
    void level(const StatusLevel aLevel);
    void message(const AText &aMsg);
    void set(const StatusLevel aLevel, const AText &aMsg);

public: // pointers

public: // debug

private:
    StatusLevel mLevel=StatusLevel::$null;
    AText mMessage;

public: // QMetaType
    const Status & it() const { return *this; }
    Status & it() { return *this; }
    Status() = default;
    ~Status() = default;
    Status(const Status &) = default;
    Status &operator=(const Status &) = default;
};

Q_DECLARE_METATYPE(Status);

inline StatusLevel Status::level() const { return mLevel; }
inline AText Status::message() const { return mMessage; }
inline QVariant Status::toVariant() const { return toString(); }
inline Status::operator QVariant() const { return toVariant(); }
inline void Status::level(const StatusLevel aLevel) { mLevel = aLevel; }
inline void Status::message(const AText &aMsg) { mMessage = aMsg; }

