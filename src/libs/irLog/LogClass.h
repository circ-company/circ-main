#pragma once

#include <QtDebug>

#include <Severity.h>

class Log
{
public: // static
    static QtMsgType qtMsgType(const Severity sev);
    static CText qtMsgType(const QtMsgType qmt);
};
