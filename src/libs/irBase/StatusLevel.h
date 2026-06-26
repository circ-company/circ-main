#pragma once

#include <QMetaType>

#include "CText.h"
#include "Named.h"


class StatusLevel
{
public: // types
    typedef QPair<int, CText> Pair;
    typedef QList<Pair> PairList;
    enum Value
    {
        $null = 0,
        $Trace = 10,        // 10-Begin Trace
        FuncArg,            // 11
        FuncLeave,          // 12
        FuncEmit,           // 13
        FuncRes,            // 14
        FuncResEn,          // 15
        FuncEnter,          // 16
        DumpHex = 21,       // 21
        Level22,
        DumpVar,            // 23
        Level24,
        DumpObj,            // 25
        TDetail = 31,       // 31
        Level32,
        TraceMsg,           // 33
        Level34,
        TProgress,          // 35
        Level36,
        TPrefer,            // 37
        TExpect,            // 38
        TAssert,            // 39

        $Info = 40,         // 40-Begin Info
        Exit,               // 41
        Detail,             // 42
        Level43,
        Info,               // 44
        Level45,
        Prefer,             // 46
        Level47,
        Progress,           // 48
        Start,              // 49

        $Warn = 50,         // 50-Begin Warn
        Warning,            // 51
        Level52,
        WPrefer,            // 53
        Level54,
        WExpect,            // 55
        Level56,
        WAssert,            // 57
        Level58,
        WMalloc,            // 59

        $Error = 60,        // 60-Begin Error
        Error,              // 61
        Level62,
        Expect,             // 63
        Level64,
        Assert,             // 65

        $Fault = 70,        // 70-Begin Fault
        Thread,             // 71
        Level72,
        MustDo,             // 73
        Level74,
        Process,            // 75
        Level76,
        MAlloc,             // 77

        Invalid = 99,       // 99-Invalid
        $max = Invalid,     // 99
    };

public: // ctors
    StatusLevel(const int val);
    StatusLevel(const CText &nam);

public: // const
    CText name() const;
    QChar prefix() const;
    int value() const;
    bool isValid() const;
    bool trace() const;
    bool info() const;
    bool warn() const;
    bool error() const;
    bool fault() const;
    bool isWarn() const;
    bool isError() const;
    bool isFault() const;
    bool inRange(const StatusLevel &lo, const StatusLevel &hi) const;
    bool equal(const StatusLevel &other) const;
    bool less(const StatusLevel &other) const;
    bool operator == (const StatusLevel &other);
    bool operator <  (const StatusLevel &other);

public: // non-const
    void nullify();
    void invalidate();
    void set(const CText &nam);
    void set(const int val);
    void min(const int val);
    void max(const int val);

public: // static
    static StatusLevel * instance();
    static void load(const PairList &pairs);
    static PairList initializer();

private:
    Value mValue=Invalid;
    static NamedInt smNamedInt;

public: // QMetaType
    StatusLevel() = default;
    ~StatusLevel() = default;
    StatusLevel(const StatusLevel &) = default;
    StatusLevel &operator=(const StatusLevel &) = default;
    StatusLevel & it() { return *this; }
    const StatusLevel & it() const { return *this; }
};

extern bool operator == (const StatusLevel &rhs, const StatusLevel &lhs);
extern bool operator <  (const StatusLevel &rhs, const StatusLevel &lhs);
extern bool operator <= (const StatusLevel &rhs, const StatusLevel &lhs);


inline CText StatusLevel::name() const { return smNamedInt.name(value()); }
inline int StatusLevel::value() const { return mValue; }
inline bool StatusLevel::trace() const { return inRange($Trace, $Info); }
inline bool StatusLevel::info() const { return inRange($Info, $Warn); }
inline bool StatusLevel::warn() const { return inRange($Warn,  $Error); }
inline bool StatusLevel::error() const { return inRange($Error, $Fault); }
inline bool StatusLevel::fault() const { return inRange($Fault, $max); }



inline bool StatusLevel::equal(const StatusLevel &other) const { return value() == other.value(); }
inline bool StatusLevel::less(const StatusLevel &other) const { return value() < other.value(); }
inline bool StatusLevel::operator ==(const StatusLevel &other) { return equal(other); }
inline void StatusLevel::invalidate() { mValue = Invalid; }
inline void StatusLevel::min(const int val) { set(qMin(value(), val)); }
inline void StatusLevel::max(const int val) { set(qMax(value(), val)); }

Q_DECLARE_METATYPE(StatusLevel);

