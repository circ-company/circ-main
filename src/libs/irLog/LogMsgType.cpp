#include "LogMsgType.h"

LogMsgType::LogMsgType() : mType($null) {;}
LogMsgType::LogMsgType(const Type typ) { set(typ) ;}
LogMsgType::LogMsgType(const QtMsgType qmt) { set(from(qmt)); }

void LogMsgType::set(const Type typ)
{
    mType = typ;
    switch (typ)
    {
    case $null:     mName = "{nul}",    mPrefix = '@';                          break;
    case Trace:     mName = "Trace",    mPrefix = '.',  mQMT = QtDebugMsg;      break;
    case Info:      mName = "Info ",    mPrefix = '-',  mQMT = QtInfoMsg;;      break;
    case Warn:      mName = "Warn ",    mPrefix = '=',  mQMT = QtWarningMsg;;   break;
    case Error:     mName = "Error",    mPrefix = '#',  mQMT = QtCriticalMsg;;  break;
    case Fault:     mName = "Fault",    mPrefix = '*',  mQMT = QtFatalMsg;;     break;
    default:        mName = "{err}",    mPrefix = '$';                          break;
    }
}

LogMsgType::Type LogMsgType::from(const CText &ctx)
{
    Type result = $null;
    if (false)                          ;
    else if (ctx.equals("Trace"))   result = Trace;
    else if (ctx.equals("Info"))    result = Info;
    else if (ctx.equals("Warn"))    result = Warn;
    else if (ctx.equals("Error"))   result = Error;
    else if (ctx.equals("Fault"))   result = Fault;
    return result;
}

LogMsgType::Type LogMsgType::from(const QtMsgType qmt)
{
    Type result = $null;
    switch (qmt)
    {
    case QtInfoMsg:         result = Info;      break;
    case QtDebugMsg:        result = Trace;     break;
    case QtWarningMsg:      result = Warn;      break;
    case QtCriticalMsg:     result = Error;     break;
    case QtFatalMsg:        result = Fault;     break;
    };
    return result;
}

LogMsgType::Type LogMsgType::from(const Severity sev)
{
    LogMsgType::Type result = $null;
    if (false) ;
    else if (sev >= Severity::$Fault)   result = Fault;
    else if (sev >= Severity::$Error)   result = Error;
    else if (sev >= Severity::$Warn)    result = Warn;
    else if (sev >= Severity::$Info)    result = Info;
    else if (sev >= Severity::$Trace)   result = Trace;
    return result;
}


