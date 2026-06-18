#include "LogFunction.h"

#include "Log.h"

LogFunction::LogFunction(const CodeContext ctx) : cmContext(ctx)
{
    LogItem li(Log::MessageOnly, StatusLevel::FuncEnter, ctx);
    li.set("Entering " + ctx.funcInfo().completeBaseName()());
    LOG->enqueue(li);
}

void LogFunction::add(const CodeValue &arg)
{
    LogItem li(Log::MessageOnly, StatusLevel::FuncArg, cmContext);
    li.set(mArgList.count(), arg);
    LOG->enqueue(li);
}

void LogFunction::leave()
{
    LogItem li(Log::MessageOnly, StatusLevel::FuncLeave, cmContext);
    LOG->enqueue(li);
}

void LogFunction::leave(const CodeValue &res)
{
    LogItem li(Log::MessageOnly, StatusLevel::FuncLeave, cmContext);
    li.set(res);
    LOG->enqueue(li);
}
