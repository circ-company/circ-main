#pragma once

#include <CodeContext.h>
#include <LogFunction.h>

#include "LogItem.h"

#define CODECONTEXT() CodeContext(Q_FUNC_INFO, __FILE__, __LINE__)

#define LOGITEM(sev, ctx) LogItem li(sev, ctx)

#define MESSAGELI(sev, msg) \
{   LogItem li(sev, CodeContext(Q_FUNC_INFO, __FILE__, __LINE__)); \
    li.message(msg); \
    LOG->enqueue(li); }

#define EXPECTLI(sev, exp, act) \
{   LOGITEM(CODECONTEXT(), sev); \
    li.expect(#exp, exp, #act, act); \
    LOG->enqueue(li); }
