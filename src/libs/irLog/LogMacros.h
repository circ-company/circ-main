#pragma once

#include <CodeContext.h>
#include <LogFunction.h>

#include "LogItem.h"

#define CODECONTEXT() CodeContext(Q_FUNC_INFO, __FILE__, __LINE__)

#define LOGITEM(sev, ctx) LogItem li(sev, ctx)

#define MESSAGELI(sev, msg) \
{   LogItem li(Log::Message, sev, CodeContext(Q_FUNC_INFO, __FILE__, __LINE__)); \
    li.set(AText(msg)); \
    LOG->enqueue(li); }

#define ASSERTLI(op, sev, bval) \
{   LOGITEM(Log::Assert, CODECONTEXT(), sev); \
    li.asert(op, bval, #bval); \
    LOG->enqueue(li); }
