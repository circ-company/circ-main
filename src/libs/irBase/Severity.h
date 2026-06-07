#pragma once

#include <QList>
#include <QMetaType>


#include "CText.h"
#include "Types.h"

class Severity
{
public: // types
    typedef QList<Severity> List;

    enum Enum : BYTE
    {
        $null = 0,
        $Trace,             //  1-Begin Trace
        FuncArg = $Trace,   //  1
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
        $Info,              // 13-Begin Info
        Detail = $Info,     // 13
        Info,               // 14
        Prefer,             // 15
        Progress,           // 16
        Exit,               // 17
        StartUp,            // 18
        $Warn,              // 19-Begin Warn
        Want = $Warn,       // 19
        Warning,            // 20
        WExpect,            // 21
        WAssert,            // 22
        WMemory,            // 23
        $Error,             // 24-Begin Error
        Error = $Error,     // 24
        Expect,             // 25
        Assert,             // 26
        $Fault,             // 27-Begin Fault
        Thread = $Fault,    // 27
        Process,            // 28
        MAlloc,             // 29
        System,             // 30
        $max,               // 31
    };
//    Q_ENUM(Enum);

public: // ctors
    Severity(const BYTE val);
    Severity(const CText nam);

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
    bool inRange(const Severity &lo, const Severity &hi) const;
    Severity evalue() const;
    BYTE value() const;
    CText name() const;
    bool equal(const Severity &other) const;
    bool less(const Severity &other) const;
    bool operator < (const Severity &other);

public: // non-const
    void nullify();
    bool set(const BYTE val);
    bool set(const CText &nam);
    void set(const Severity other);
    void max(const Severity other);
    void min(const Severity other);

private:
    Enum mEnum=$null;

public: // QMetaType
    Severity() = default;
    ~Severity() = default;
    Severity(const Severity &) = default;
    Severity &operator=(const Severity &) = default;
    const Severity & it() const { return *this; }
    Severity & it() { return *this; }
};

Q_DECLARE_METATYPE(Severity);

extern bool operator < (const Severity &rhs, const Severity &lhs);
extern bool operator <= (const Severity &rhs, const Severity &lhs);

inline bool Severity::isNull() const { return Enum::$null == value(); }
inline bool Severity::isValid() const { return inRange(Enum::$Trace, Enum::$max); }
inline bool Severity::trace() const { return inRange(Enum::$Trace, Enum::$Info); }
inline bool Severity::info() const { return inRange(Enum::$Info, Enum::$Warn); }
inline bool Severity::warn() const { return inRange(Enum::$Warn,Enum:: $Error); }
inline bool Severity::error() const { return inRange(Enum::$Error, Enum::$Fault); }
inline bool Severity::fault() const { return inRange(Enum::$Fault, Enum::$max); }
inline bool Severity::isWarn() const { return inRange(Enum::$Warn, Enum::$max); }
inline bool Severity::isError() const { return inRange(Enum::$Error, Enum::$max); }
inline BYTE Severity::value() const { return BYTE(evalue().mEnum); }
inline bool Severity::equal(const Severity &other) const { return value() == other.value(); }
inline bool Severity::less(const Severity &other) const { return value() < other.value(); }
inline bool Severity::operator < (const Severity &other) { return less(other); }
inline void Severity::nullify() { mEnum = Enum::$null; }
//inline void Severity::set(const Enum other) { mEnum = other; }
inline void Severity::max(const Severity other) { it() = qMax(it(), other); }
inline void Severity::min(const Severity other) { it() = qMin(it(), other); }
