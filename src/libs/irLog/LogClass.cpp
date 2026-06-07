#include "LogClass.h"

#include <AText.h>
#include <Types.h>

// static
QtMsgType Log::qtMsgType(const Severity sev)
{
    QtMsgType result = QtMsgType(-1);
         if (sev.fault())       result = QtFatalMsg;
    else if (sev.error())       result = QtCriticalMsg;
    else if (sev.warn())        result = QtWarningMsg;
    else if (sev.info())        result = QtInfoMsg;
    else if (sev.trace())       result = QtDebugMsg;
    return result;
}

CText Log::qtMsgName(const QtMsgType qmt)
{
    CText result = "{invalid}";
    switch (qmt)
    {
    case QtDebugMsg:    result = "Trace";       break;
    case QtInfoMsg:     result = "Info";        break;
    case QtWarningMsg:  result = "Warn";        break;
    case QtCriticalMsg: result = "Error";       break;
    case QtFatalMsg:    result = "Fault";       break;
    }
    return result;
}

