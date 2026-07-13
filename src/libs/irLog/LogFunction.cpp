#include "LogFunction.h"

#include "Log.h"
#include "LogItem.h"
#include "LogMacros.h"

LogFunction::LogFunction(const CodeContext ctx)
    : cmContext(ctx)
{
    LogItem tLI(Log::Function, StatusLevel::FuncEnter, ctx);
    tLI.set("Entering " + ctx.toDebugString(false));
    LOG->enqueue(tLI);
}

void LogFunction::addArgument(const QVariant &aArgVal, const AText &aArgText)
{

}

void LogFunction::emitSignal(const CText &aSigText)
{

}

void LogFunction::emitArgument(const CText &aSigText, const QVariant &aArgVal, const AText &aArgText)
{

}

void LogFunction::returnVoid()
{

}

void LogFunction::returnValue(const QVariant &aArgVal, const AText &aArgText)
{

}
