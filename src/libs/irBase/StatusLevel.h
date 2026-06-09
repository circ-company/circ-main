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
        FuncArg,   //  1
        $Trace = FuncArg,             //  1-Begin Trace
        FuncLeave,          //  2
        FuncEnter,          //  3
        DumpHex,            //  4
        DumpVar,            //  5
        DumpObj,            //  6
        TDetail,            //  7
        TraceMsg,           //  8
        TProgress,          //  9
        TPrefer,            // 10
        TExpect,            // 11
        TAssert,            // 12
        Exit,               // 17
        $Info = Exit,              // 13-Begin Info
        Detail,     // 13
        Info,               // 14
        Prefer,             // 15
        Progress,           // 16
        Start,            // 18
        Warning,              // 19-Begin Warn
        $Warn = Warning,       // 19
        WPrefer,            // 20
        WExpect,            // 21
        WAssert,            // 22
        WMemory,            // 23
        Error,             // 24-Begin Error
        $Error = Error,     // 24
        Expect,             // 25
        Assert,             // 26
        Thread,    // 27
        $Fault = Thread,             // 27-Begin Fault
        Process,            // 28
        MAlloc,             // 29
        System,             // 30
        Invalid,            // 31
        $max = Invalid,               // 31
    };

public: // ctors
    StatusLevel(const int val);
    StatusLevel(const CText &nam);

public: // const
    CText name() const;
    int value() const;
    bool isValid() const;
    bool trace() const;
    bool info() const;
    bool warn() const;
    bool error() const;
    bool fault() const;
    bool isWarn() const;
    bool isError() const;
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
inline bool StatusLevel::isWarn() const { return inRange($Warn, $max); }
inline bool StatusLevel::isError() const { return inRange($Error, $max); }
inline bool StatusLevel::equal(const StatusLevel &other) const { return value() == other.value(); }
inline bool StatusLevel::less(const StatusLevel &other) const { return value() < other.value(); }
inline void StatusLevel::nullify() { mValue = $null; }
inline void StatusLevel::invalidate() { mValue = Invalid; }
inline void StatusLevel::min(const int val) { set(qMin(value(), val)); }
inline void StatusLevel::max(const int val) { set(qMax(value(), val)); }

Q_DECLARE_METATYPE(StatusLevel);

