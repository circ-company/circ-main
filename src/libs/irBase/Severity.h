#pragma once

#include <QObject>

#include "CText.h"
#include "Types.h"

class Severity : public QObject
{
    Q_GADGET
public: // types
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
    Q_ENUM(Enum);

public: // ctors
    Severity(); // null
    Severity(const BYTE val);
    Severity(const CText nam);
    ~Severity();

public: // const
    bool isNull() const;
    bool trace() const;
    bool info() const;
    bool warn() const;
    bool error() const;
    bool fault() const;
    bool isWarn() const;
    bool isError() const;
    bool inRange(const Enum &lo, const Enum &hi) const;
    Enum evalue() const;
    BYTE value() const;
    CText name() const;

public: // non-const
    void nullify();
    bool set(const BYTE val);
    bool set(const CText nam);
    void set(const Enum other);

private:
    Enum mEnum=$null;
};

inline bool Severity::isNull() const { return $null == evalue(); }
inline bool Severity::trace() const { return inRange($Trace, $Info); }
inline bool Severity::info() const { return inRange($Info, $Warn); }
inline bool Severity::warn() const { return inRange($Warn, $Error); }
inline bool Severity::error() const { return inRange($Error, $Fault); }
inline bool Severity::fault() const { return inRange($Fault, $max); }
inline bool Severity::isWarn() const { return inRange($Warn, $max); }
inline bool Severity::isError() const { return inRange($Error, $max); }
inline void Severity::nullify() { mEnum = $null; }
inline void Severity::set(const Enum other) { mEnum = other; }
