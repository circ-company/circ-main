#pragma once

#include <Severity.h>
#include <CodeValue.h>
#include <CodeValueList.h>
#include <CodeContext.h>

class LogFunction
{
public: // ctors
    LogFunction(const CodeContext ctx);

public: // non-const
    void add(const CodeValue &arg);
    void leave();
    void leave(const CodeValue &arg);

private:
    CodeContext cmContext;
    CodeValueList mArgList;
};

