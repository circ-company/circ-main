#pragma once

#include <CodeContext.h>
#include <LogFunction.h>

#include "LogItem.h"

#define CODECONTEXT() CodeContext(Q_FUNC_INFO, __FILE__, __LINE__)

#define LOGITEM(typ, sev, ctx) LogItem li(typ, sev, ctx)

#define MESSAGELI(sev, msg) \
{   LogItem li(Log::Message, sev, CODECONTEXT()); \
    li.set(AText(msg)); \
    LOG->enqueue(li); }

#define ASSERTLI(op, sev, bval) \
{   LOGITEM(Log::Assert, sev, CODECONTEXT()); \
    li.asert(op, bval, #bval); \
    LOG->enqueue(li); }

#define FORMATLI(sev, cvfmt, cv1, cv2, cv3, cv4) \
{   LOGITEM(Log::Formatted, sev,  CODECONTEXT()); \
    li.set(0, cvfmt), li.set(1, cv1), li.set(2, cv2), \
    li.set(3, cv3), li.set(4, cv4); \
    LOG->enqueue(li); }

