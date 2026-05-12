#include "Log.h"

#include <AText.h>
#include <Types.h>

// static
QtMsgType Log::qtMsgType(const Severity sev)
{
    QtMsgType result = QtMsgType(0);
         if (sev > Severity::$Fault)    result = QtFatalMsg;
    else if (sev > Severity::$Error)    result = QtCriticalMsg;
    else if (sev > Severity::$Warning)  result = QtWarningMsg;
    else if (sev > Severity::$Info)     result = QtInfoMsg;
    else if (sev > Severity::$Trace)    result = QtDebugMsg;
    return result;
}

CText Log::qtMsgType(const QtMsgType qmt)
{
    CText result = "{invalid}";
    switch (qmt)
    {
    case QtDebugMsg:    result = "Trace";       break;
    case QtInfoMsg:     result = "Info";        break;
    case QtWarningMsg:  result = "Warning";     break;
    case QtCriticalMsg: result = "Error";       break;
    case QtFatalMsg:    result = "Fault";       break;
    }
    return result;
}

