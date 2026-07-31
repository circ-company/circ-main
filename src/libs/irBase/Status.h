#pragma once

#include <QMetaType>
#include <QList>
#include <QPair>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>
class QFile;

#include "AText.h"
#include "ATextList.h"
#include "StatusLevel.h"
#include "Types.h"

class Status
{
public: // types
    typedef QPair<Milliseconds, AText> TimeText;
    typedef QList<TimeText> TimeTextList;

public: // ctors
    Status(const StatusLevel aLevel);
    Status(const StatusLevel aLevel, const AText &aMsg);

public: // const
    StatusLevel level() const;
    AText timetext() const;
    Milliseconds time() const;
    AText message() const;
    ATextList notes() const;
    QString toString() const;
    QStringList toStrings() const;
    QVariant toVariant() const;
    operator QVariant () const;

public: // non-const
    void clear();
    void level(const StatusLevel aLevel);
    void message(const AText &aMsg);
    void note(const AText &aMsg);
    void set(const StatusLevel aLevel, const AText &aMsg);
    void set(const StatusLevel aLevel, QFile * pFile);

public: // pointers

public: // debug

private:
    StatusLevel mLevel=StatusLevel::$null;
    TimeText mMessage;
    TimeTextList mNotes;

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
inline Milliseconds Status::time() const { return mMessage.first; }
inline AText Status::message() const { return mMessage.second; }
inline QVariant Status::toVariant() const { return toString(); }
inline Status::operator QVariant() const { return toVariant(); }
inline void Status::level(const StatusLevel aLevel) { mLevel = aLevel; }


