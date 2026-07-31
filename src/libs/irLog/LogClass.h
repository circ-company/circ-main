#pragma once

#include <QObject>

#include <QtDebug>
#include <QVariant>

#include <StatusLevel.h>

class Log : QObject
{
    Q_GADGET
public: // types
    enum ItemType
    {
        $nullType = 0,
        MessageOnly,
        Function,
        Formatted,
        ReturnVoid,
        ReturnValue,
        Assert,
        Expect,
        Malloc,
        Dump,
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
    Q_ENUM(Operator);


public: // static
    static bool evaluate(const Operator aOp, const QVariant &aVar);
    static bool evaluate(const Operator aOp, const QVariant &aExp, const QVariant &aAct);
    static QtMsgType qtMsgType(const StatusLevel sl);
    static CText qtMsgName(const QtMsgType qmt);
    static CText opName(const Operator aOp);
};
