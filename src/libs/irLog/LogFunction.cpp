#include "LogFunction.h"

#include "Log.h"

LogFunction::LogFunction(const CodeContext ctx) : cmContext(ctx)
{
    LogItem li(Log::ItemOnly, StatusLevel::FuncEnter, ctx);
    li.set("Entering " + ctx.funcInfo().completeBaseName()());
    LOG->enqueue(li);
}

void LogFunction::add(const CodeValue &arg)
{
    LogItem li(Log::ItemOnly, StatusLevel::FuncArg, cmContext);
    li.set(mArgList.count(), arg);
    LOG->enqueue(li);
}

void LogFunction::leave()
{
    LogItem li(Log::ItemOnly, StatusLevel::FuncLeave, cmContext);
    LOG->enqueue(li);
}

void LogFunction::leave(const CodeValue &arg)
{
    LogItem li(Log::ItemOnly, StatusLevel::FuncLeave, cmContext);
    li.set(arg);
    LOG->enqueue(li);
}
