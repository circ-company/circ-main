#pragma once

#include <CodeContext.h>
#include <CText.h>
#include <StatusLevel.h>

class LogFunction
{
public: // types

public: // ctors
    LogFunction(const CodeContext ctx);

public: // non-const
    void addArgument(const QVariant &aArgVal , const AText &aArgText);
    void emitSignal(const CText &aSigText);
    void emitArgument(const CText &aSigText, const QVariant &aArgVal,
                      const AText &aArgText);
    void returnVoid();
    void returnValue(const QVariant &aArgVal , const AText &aArgText);

private:

private:
    CodeContext cmContext;
};

