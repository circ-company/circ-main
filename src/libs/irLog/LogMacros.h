#pragma once

#include <CodeContext.h>

#include "Log.h"
#include "LogEngine.h"
#include "LogFunction.h"
#include "LogItem.h"

#define LOGITEM(typ, lvl, ctx) LogItem li(typ, lvl, ctx)

#define CHECKPTR(sev, ptr) \
{ \
    LOGITEM(Log::Pointer, sev, CODECONTEXT()); \
    li.pointer(ptr, #ptr); \
    LOG->enqueue(li); \
    LOG->flush(); \
    if(li.isFault()) Q_ASSERT(false); \
} \

#define MESSAGELI(sev, msg) \
{ \
    LogItem li(Log::MessageOnly, sev, CODECONTEXT()); \
    li.text(AText(msg)); \
    LOG->enqueue(li); \
    LOG->flush(); \
    if(li.isFault()) Q_ASSERT(false); \
} \

#define ASSERTLI(op, sev, bval) \
{ \
    LOGITEM(Log::Assert, sev, CODECONTEXT()); \
    li.assertIs(op, bval, #bval); \
    LOG->enqueue(li); \
    LOG->flush(); \
    if(li.isFault()) Q_ASSERT(false); \
} \

#define EXPECT2LI(op, sev, act) \
{ \
    LOGITEM(Log::Expect, sev, CODECONTEXT()); \
    li.expect(op, act, #act); \
    LOG->enqueue(li); \
    LOG->flush(); \
    if(li.isFault()) Q_ASSERT(false); \
} \

#define EXPECT4LI(op, sev, exp, act) \
{ \
    LOGITEM(Log::Expect, sev, CODECONTEXT()); \
    li.expect(op, exp, #exp, act, #act); \
    LOG->enqueue(li); \
    LOG->flush(); \
    if(li.isFault()) Q_ASSERT(false); \
} \



