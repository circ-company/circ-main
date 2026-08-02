#include "LogFunction.h"

#include "Log.h"
#include "LogItem.h"
#include "LogMacros.h"

LogFunction::LogFunction(const CodeContext ctx)
    : cmContext(ctx)
{
    LogItem tLI(Log::Function, StatusLevel::FuncEnter, cmContext);
    tLI.set(AText("Entering: %1"));
    tLI.set(QVariant(cmContext.funcInfo().completeBaseName()));
    LOG->enqueue(tLI);
}

void LogFunction::addArgument(const QVariant &aArgVal, const AText &aArgText, const CText &aArgType)
{
    const QMetaType cQMT = QMetaType::fromName(aArgType);
    LogItem tLI(Log::Function, StatusLevel::FuncArg, cmContext);
    tLI.set(AText("Argument: %1=<%2> %3(%4)"));
    tLI.set(QVariant(aArgText));
    tLI.set(aArgVal);
    tLI.set(QVariant(cQMT.name()));
    tLI.set(QVariant(cQMT.id()));
    LOG->enqueue(tLI);
}

void LogFunction::emitSignal(const CText &aSigText)
{
    LogItem tLI(Log::Function, StatusLevel::FuncEmit, cmContext);
    tLI.set(AText("Emit: %1"));
    tLI.set(QVariant(aSigText));
    LOG->enqueue(tLI);
}

void LogFunction::emitArgument(const CText &aSigText, const QVariant &aArgVal,
                               const AText &aArgText, const CText &aArgType)
{
    const QMetaType cQMT = QMetaType::fromName(aArgType);
    LogItem tLI(Log::Function, StatusLevel::FuncEmit, cmContext);
    tLI.set(AText("Emit: %1(%2=<%3>) %4(%5)"));
    tLI.set(QVariant(aSigText));
    tLI.set(QVariant(aArgText));
    tLI.set(aArgVal);
    tLI.set(QVariant(cQMT.name()));
    tLI.set(QVariant(cQMT.id()));
    LOG->enqueue(tLI);
}

void LogFunction::returnVoid()
{
    LogItem tLI(Log::Function, StatusLevel::FuncLeave);
    tLI.set(AText("Return: void from %1"));
    tLI.set(QVariant(cmContext.toDebugString()));
    LOG->enqueue(tLI);
}

void LogFunction::returnValue(const QVariant &aArgVal,
                              const char *aArgText, const char *aArgType)
{
    const QMetaType cQMT = QMetaType::fromName(aArgType);
    LogItem tLI(Log::Function, StatusLevel::FuncLeave, cmContext);
    tLI.set(AText("Return: %1=<%2> %3(%4) from %5"));
    tLI.set(QVariant(aArgText));
    tLI.set(aArgVal);
    tLI.set(QVariant(cQMT.name()));
    tLI.set(QVariant(cQMT.id()));
    tLI.set(QVariant(AText(cmContext.toDebugString(false))));
    LOG->enqueue(tLI);
}

