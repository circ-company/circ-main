#pragma once

#include <QObject>

#include "CText.h"
#include "Types.h"

class LogOperator
{
public: // types
    enum Enum : BYTE
    {
        $null = 0,
        True,
        False,
        Is,
        Not,
        Invert,
        Equal,
        NotEqual,
        Less,
        LessEqual,
        Greater,
        GreaterEqual,
        NotLess = GreaterEqual,
        NotGreater = LessEqual,
        $max
    };

public: // ctors
    LogOperator(); // null
    LogOperator(const BYTE val);
    LogOperator(const CText nam);
    ~LogOperator();

public: // const
    bool isNull() const;
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
    Enum mEnum=Enum::$null;

};

inline LogOperator::Enum LogOperator::evalue() const { return mEnum; }
inline bool LogOperator::isNull() const { return Enum::$null == mEnum; }
inline BYTE LogOperator::value() const { return BYTE(mEnum); }
inline void LogOperator::nullify() { mEnum = Enum::$null; }
inline void LogOperator::set(const Enum other) { mEnum = other; }
