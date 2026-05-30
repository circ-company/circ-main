#include "LogFunction.h"

#include "Log.h"

LogFunction::LogFunction(const CodeContext ctx) : cmContext(ctx)
{
    LogItem li(Severity::FuncEnter, ctx);
    LOG->enqueue(li);
}

void LogFunction::add(const Severity sev, const CodeValue &arg)
{
    LogItem li(sev);
    li.argument(mArgList.count(), arg);
    mArgList.append(arg);
    LOG->enqueue(li);
}

void LogFunction::leave(const CodeContext ctx)
{
    LogItem li(Severity::FuncLeave, ctx);
    LOG->enqueue(li);
}

void LogFunction::leave(const CodeContext ctx, const CodeValue &arg)
{
    LogItem li(Severity::FuncLeave, ctx);
    li.returnValue(arg);
    LOG->enqueue(li);
}
