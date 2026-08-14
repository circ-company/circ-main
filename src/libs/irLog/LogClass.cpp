#include "LogClass.h"

#include <AText.h>
#include <EnumHelper.h>
#include <Sign.h>
#include <TriBool.h>
#include <Types.h>

// static
bool Log::evaluate(const Operator aOp, const QVariant &aVar)
{
    TriBool result;
    switch (aOp)
    {
    case Is:
    case True:      result.set(aVar.toBool());      break;
    case Not:
    case False:     result.set( ! aVar.toBool());   break;
    default:                                        break;
    };

    Q_ASSERT(result.valid());
    return result;
}

bool Log::evaluate(const Operator aOp, const QVariant &aExp, const QVariant &aAct)
{
    TriBool result;
    Sign tSign;
    tSign.set(aExp, aAct);
    switch (aOp)
    {
    case Equal:         result.set(tSign.state() == TriBool::Null);     break;
    case NotEqual:      result.set(tSign.state() != TriBool::Null);     break;
    case Less:          result.set(tSign.state() <  TriBool::False);    break;
    case LessEqual:     result.set(tSign.state() <= TriBool::False);    break;
    case Greater:       result.set(tSign.state() >  TriBool::True);     break;
    case GreaterEqual:  result.set(tSign.state() >= TriBool::True);     break;
    default:                                                            break;
    };
    Q_ASSERT(result.valid());
    return result;
}

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

// static
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

// static
CText Log::opName(const Operator aOp)
{
    return EnumHelper::name<Operator>(aOp);
}

