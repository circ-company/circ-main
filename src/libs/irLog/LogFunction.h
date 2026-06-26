#pragma once

#include <ArgumentInfo.h>
#include <ArgumentInfoList.h>
#include <CodeContext.h>
#include <CText.h>
#include <StatusLevel.h>

class LogFunction
{
public: // types
    struct EmitArgs
    {
        int FileLine;
        CText EmitName;
        ArgumentInfoList EmitArgs;
    };

public: // ctors
    LogFunction(const CodeContext ctx);

public: // non-const
    void addArgument(const ArgumentInfo &arg);
    int emitSignal(const int aLineAbove, const CText &sigName);
    void emitArgument(const int aEmitLine, const ArgumentInfo &arg);
    void returnVoid();
    void returnValue(const ArgumentInfo &arg);

private:
    void closeOut();

private:
    CodeContext cmContext;
    ArgumentInfoList mArgList;
    QMap<int, EmitArgs> mEmitLineArgsMap;
    ArgumentInfo mReturnArg;
};

