#include "LogFunction.h"

#include "Log.h"
#include "LogItem.h"
#include "LogMacros.h"

LogFunction::LogFunction(const CodeContext ctx)
    : cmContext(ctx)
{
}

void LogFunction::addArgument(const ArgumentInfo &arg)
{
    mArgList.append(arg);
}

int LogFunction::emitSignal(const int aLineAbove, const CText &aSigName)
{
    EmitArgs tEA = { aLineAbove - 1, aSigName, ArgumentInfoList() };
    mEmitLineArgsMap.insert(tEA.FileLine, tEA);
    return tEA.FileLine;
}

void LogFunction::emitArgument(const int aEmitLine, const ArgumentInfo &arg)
{
    mEmitLineArgsMap[aEmitLine].EmitArgs.append(arg);
}

void LogFunction::returnVoid()
{
    mReturnArg.clear();
}

void LogFunction::returnValue(const ArgumentInfo &arg)
{
    mReturnArg = arg;
}

void LogFunction::closeOut()
{
    LogItem liEnter(Log::Function, StatusLevel::FuncEnter, cmContext);
    LOG->enqueue(liEnter);
    foreach (const ArgumentInfo cAI, mArgList)
    {
        LogItem liArg(Log::Function, StatusLevel::FuncArg, cmContext);
        liArg.set(cAI);
        LOG->enqueue(liArg);
    }
    foreach (const EmitArgs cEA, mEmitLineArgsMap.values())
    {
        LogItem liEmit(Log::Function, StatusLevel::FuncEmit,
                       CodeContext(cmContext.qfiText(),
                                   cmContext.fileName(),
                                   cEA.FileLine));
        LOG->enqueue(liEmit);
    }
    if ( ! mReturnArg.isNull())
    {
        LogItem liReturn(Log::Function, StatusLevel::FuncLeave, cmContext);
        liReturn.set(mReturnArg);
        LOG->enqueue(liReturn);
    }
}
