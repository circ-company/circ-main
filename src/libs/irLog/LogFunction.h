#pragma once

#include <CodeContext.h>
#include <CText.h>
#include <StatusLevel.h>
#include <Types.h>

class LogFunction
{
public: // types

public: // ctors
    LogFunction(const CodeContext ctx);

public: // const

public: // non-const
    void addArgument(const QVariant &aArgVal , const AText &aArgText,
                     const CText &aArgType);
    void emitSignal(const CText &aSigText);
    void emitArgument(const CText &aSigText, const QVariant &aArgVal,
                      const AText &aArgText, const CText &aArgType);
    void returnVoid();
    void returnValue(const QVariant &aArgVal ,
                     const char * aArgText, const char * aArgType);

private:

private:
    CodeContext cmContext;
};


