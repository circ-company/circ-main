#pragma once

#include <QtDebug>

#include <Severity.h>

class Log
{
public: // types
    enum ItemType
    {
        $null = 0,
        ItemOnly,
        FuncArgument,
        Message,
        Formatted,
        ReturnVoid,
        ReturnValue,
        Assert,
        Troll,
        $end
    };

public: // static
    static QtMsgType qtMsgType(const Severity sev);
    static CText qtMsgName(const QtMsgType qmt);
};
