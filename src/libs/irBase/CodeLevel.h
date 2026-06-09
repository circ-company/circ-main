#pragma once

#include <QObject>

#include <QList>

#include "CText.h"
#include "Types.h"

class CodeLevel : public QObject
{
    Q_OBJECT
public: // types
    typedef QList<CodeLevel> List;

    enum Enum
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
        Detail,     // 13
        $Info = Detail,              // 13-Begin Info
        Info,               // 14
        Prefer,             // 15
        Progress,           // 16
        Exit,               // 17
        StartUp,            // 18
        Warn,              // 19-Begin Warn
        $Warn = Warn,       // 19
        Warning,            // 20
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
        $max,               // 31
    };
    Q_ENUM(Enum);

public: // ctors
    CodeLevel(const BYTE val);
    CodeLevel(const CText &nam);

public: // const
    bool isNull() const;
    bool isValid() const;
    bool trace() const;
    bool info() const;
    bool warn() const;
    bool error() const;
    bool fault() const;
    bool isWarn() const;
    bool isError() const;
    bool inRange(const CodeLevel &lo, const CodeLevel &hi) const;
    Enum evalue() const;
    int value() const;
    CText name() const;
    bool equal(const CodeLevel &other) const;
    bool less(const CodeLevel &other) const;
    bool operator < (const CodeLevel &other);

public: // non-const
    void nullify();
    bool set(const int val);
    bool set(const CText &key);
    void set(const CodeLevel other);
    void max(const CodeLevel other);
    void min(const CodeLevel other);

public: // pointer
    const CodeLevel * it() const { return this; }
    CodeLevel * it() { return this; }

private:
    Enum mEnum=$null;

};

extern bool operator == (const CodeLevel &rhs, const CodeLevel &lhs);
extern bool operator <  (const CodeLevel &rhs, const CodeLevel &lhs);
extern bool operator <= (const CodeLevel &rhs, const CodeLevel &lhs);

inline bool CodeLevel::isNull() const { return Enum::$null == value(); }
inline bool CodeLevel::isValid() const { return inRange(Enum::$Trace, Enum::$max); }
inline bool CodeLevel::trace() const { return inRange(Enum::$Trace, Enum::$Info); }
inline bool CodeLevel::info() const { return inRange(Enum::$Info, Enum::$Warn); }
inline bool CodeLevel::warn() const { return inRange(Enum::$Warn, Enum:: $Error); }
inline bool CodeLevel::error() const { return inRange(Enum::$Error, Enum::$Fault); }
inline bool CodeLevel::fault() const { return inRange(Enum::$Fault, Enum::$max); }
inline bool CodeLevel::isWarn() const { return inRange(Enum::$Warn, Enum::$max); }
inline bool CodeLevel::isError() const { return inRange(Enum::$Error, Enum::$max); }
inline CodeLevel::Enum CodeLevel::evalue() const { return mEnum; }
inline int CodeLevel::value() const { return int(mEnum); }
inline bool CodeLevel::equal(const CodeLevel &other) const { return value() == other.value(); }
inline bool CodeLevel::less(const CodeLevel &other) const { return value() < other.value(); }
inline bool CodeLevel::operator < (const CodeLevel &other) { return less(other); }
inline void CodeLevel::nullify() { mEnum = Enum::$null; }
inline void CodeLevel::set(const CodeLevel other) { mEnum = other.evalue(); }
inline void CodeLevel::max(const CodeLevel other) { set(qMax(value(), other.value())); }
inline void CodeLevel::min(const CodeLevel other) { set(qMin(value(), other.value())); }
