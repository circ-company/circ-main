#include "LogFunction.h"

#include "LogEngine.h"
#include "LogItem.h"

LogFunction::LogFunction(const CodeContext ctx)
    : cmContext(ctx)
{
    CodeContext::increaseLevel();
    LogItem tLI(Log::Function, StatusLevel::FuncEnter, cmContext);
    tLI.format("Entering: %1");
    tLI.text(cmContext.funcInfo().completeBaseName());
    LOG->enqueue(tLI);
}

void LogFunction::addArgument(const QVariant &aArgVal,
                              const AText &aArgText,
                              const CText &aArgType)
{
    const QMetaType cQMT = QMetaType::fromName(aArgType);
    LogItem tLI(Log::Function, StatusLevel::FuncArg, cmContext);
    tLI.format(AText("Argument: %1=<%2> %3(%4)"));
    tLI.text(aArgText);
    tLI.set(aArgVal);
    tLI.text(cQMT.name());
    tLI.set(cQMT.id());
    LOG->enqueue(tLI);
}

void LogFunction::emitSignal(const CText &aSigText)
{
    LogItem tLI(Log::Function, StatusLevel::FuncEmit, cmContext);
    tLI.format("Emit: %1");
    tLI.text(aSigText);
    LOG->enqueue(tLI);
}

void LogFunction::emitArgument(const CText &aSigText,
                               const QVariant &aArgVal,
                               const AText &aArgText,
                               const CText &aArgType)
{
    const QMetaType cQMT = QMetaType::fromName(aArgType);
    LogItem tLI(Log::Function, StatusLevel::FuncEmit, cmContext);
    tLI.format(AText("Emit: %1(%2=<%3>) %4(%5)"));
    tLI.text(aSigText);
    tLI.text(aArgText);
    tLI.set(aArgVal);
    tLI.text(cQMT.name());
    tLI.set(cQMT.id());
    LOG->enqueue(tLI);
}

void LogFunction::returnVoid()
{
    LogItem tLI(Log::Function, StatusLevel::FuncReturn, cmContext);
    tLI.format("Return: void from %1");
    tLI.text(cmContext.funcInfo().completeBaseName());
    LOG->enqueue(tLI);
    CodeContext::decreaseLevel();
}

void LogFunction::returnValue(const QVariant &aArgVal,
                              const char *aArgText, const char *aArgType)
{
    const QMetaType cQMT = QMetaType::fromName(aArgType);
    LogItem tLI(Log::Function, StatusLevel::FuncReturn, cmContext);
    tLI.format("Return: %1=<%2> %3(%4) from %5");
    tLI.text(aArgText);
    tLI.set(aArgVal);
    tLI.text(cQMT.name());
    tLI.set((cQMT.id()));
    tLI.text(cmContext.funcInfo().completeBaseName());
    LOG->enqueue(tLI);
    CodeContext::decreaseLevel();
}

