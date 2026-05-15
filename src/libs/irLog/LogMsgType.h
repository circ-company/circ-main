#pragma once

#include <QtLogging>

#include <CText.h>
#include <Severity.h>

class LogMsgType
{
public: // types
    enum Type { $null = 0, Trace, Info, Warn, Error, Fault, $max };

public: // ctors
    LogMsgType();
    LogMsgType(const Type typ);
    LogMsgType(const QtMsgType qmt);

public: // const
    Type type() const;
    CText name() const;
    char prefix() const;
    QtMsgType qmt() const;

public: // non-const
    void set(const Type typ);

public: // static
    static Type from(const CText &ctx);
    static Type from(const QtMsgType qmt);
    static Type from(const Severity sev);

private:
    Type mType;
    CText mName;
    char mPrefix;
    QtMsgType mQMT;
};
