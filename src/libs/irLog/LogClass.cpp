#include "LogClass.h"

#include <AText.h>
#include <Types.h>

// static
QtMsgType Log::qtMsgType(const StatusLevel sl)
{
    QtMsgType result = QtMsgType(0);
         if (sl.fault())       result = QtFatalMsg;
    else if (sl.error())       result = QtCriticalMsg;
    else if (sl.warn())        result = QtWarningMsg;
    else if (sl.info())        result = QtInfoMsg;
    else if (sl.trace())       result = QtDebugMsg;
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

