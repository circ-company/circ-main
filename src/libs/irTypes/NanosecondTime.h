#pragma once

#include <QDateTime>
#include <QString>

#include "StructTM.h"
#include "Types.h"

class NanosecondTime
{
public: // types

public: // ctors
    NanosecondTime(const Nanoseconds kTicks); // 0=use current
    NanosecondTime(const std::time_t stt);

public: // const
    Nanoseconds value() const;
    bool isNull() const;
    bool isValid() const;
    std::time_t timeT() const;
    SQWORD hecto() const;
    QDateTime toDateTime(void) const;
    QString toString(const QString & format=QString()) const;
    QString nanoString() const;
    QString timeString() const;
    Nanoseconds operator() () const;


public: // non-const
    void set(const Nanoseconds kTicks);  // 0=use current
    void set(const std::time_t stt);
    void hecto(const SQWORD hns);
    void nullify();

public: // static
    static Nanoseconds base(void);
    static Nanoseconds current(void);
    static Nanoseconds nanoFactor();
    static Nanoseconds nanoYear(const WORD year);
    static std::time_t epochSTT(const Nanoseconds tick=0);
    static Nanoseconds offset(const StructTM other);

private:
    Nanoseconds mNanoTicks=-1;
    static const Nanoseconds smBaseNST;

public: // QMetaType
    NanosecondTime() = default;
    ~NanosecondTime() = default;
    NanosecondTime(const NanosecondTime & other) = default;
    NanosecondTime &operator=(const NanosecondTime & other) = default;
};

Q_DECLARE_METATYPE(NanosecondTime);

inline Nanoseconds NanosecondTime::value() const { return mNanoTicks; }
inline Nanoseconds NanosecondTime::operator()() const { return value(); }
inline void NanosecondTime::nullify() { mNanoTicks = -1; }
inline Nanoseconds NanosecondTime::base() { return smBaseNST; }
inline Nanoseconds NanosecondTime::nanoFactor() { return 1000000000LL; }
