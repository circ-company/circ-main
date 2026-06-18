#pragma once

#include <CodeValue.h>
#include <CodeValueList.h>
#include <CodeContext.h>
#include <StatusLevel.h>

class LogFunction
{
public: // ctors
    LogFunction(const CodeContext ctx);

public: // non-const
    void add(const CodeValue &arg);
    void leave();
    void leave(const CodeValue &res);

private:
    CodeContext cmContext;
    CodeValueList mArgList;
};

