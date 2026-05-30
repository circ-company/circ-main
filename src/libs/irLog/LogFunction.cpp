#include "LogFunction.h"

#include "Log.h"

LogFunction::LogFunction(const CodeContext ctx) : cmContext(ctx)
{
    LogItem li(Log::ItemOnly, Severity::FuncEnter, ctx);
    LOG->enqueue(li);
}

void LogFunction::add(const CodeValue &arg)
{
    LogItem li(Log::FuncArgument, Severity::FuncArg, cmContext);
    li.set(mArgList.count(), arg);
    LOG->enqueue(li);
}

void LogFunction::leave()
{
    LogItem li(Log::ReturnVoid, Severity::FuncLeave, cmContext);
    LOG->enqueue(li);
}

void LogFunction::leave(const CodeValue &arg)
{
    LogItem li(Log::ReturnValue, Severity::FuncLeave, cmContext);
    li.set(arg);
    LOG->enqueue(li);
}
