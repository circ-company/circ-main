#pragma once

#include <QByteArray>
#include <QStringList>

#include <Severity.h>

#include "LogMacros.h"

class Log
{

public:
    static QtMsgType qtMsgType(const Severity sev);
    static CText qtMsgType(const QtMsgType qmt);
};
