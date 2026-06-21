#pragma once

#include <QtDebug>

#include <StatusLevel.h>

class Log
{
public: // types
    enum ItemType
    {
        $nullType = 0,
        MessageOnly,
        FuncArgument,
        Message,
        Formatted,
        ReturnVoid,
        ReturnValue,
        Assert,
        Troll,
        $maxType
    };

    enum Operator : BYTE
    {
        $nullOperator = 0,
        True,
        False,
        Is,
        Not,
        Invert,
        Equal,
        NotEqual,
        Less,
        LessEqual,
        Greater,
        GreaterEqual,
        NotLess = GreaterEqual,
        NotGreater = LessEqual,
        $maxOperator
    };


public: // static
    static QtMsgType qtMsgType(const StatusLevel sl);
    static CText qtMsgName(const QtMsgType qmt);
};
