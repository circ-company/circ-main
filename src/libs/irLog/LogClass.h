#pragma once

#include <QtDebug>

#include <StatusLevel.h>

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
    static QtMsgType qtMsgType(const StatusLevel sl);
    static CText qtMsgName(const QtMsgType qmt);
};
