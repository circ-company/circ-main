#pragma once

#include <CodeContext.h>
#include <LogFunction.h>

#include "LogItem.h"

#define LOGITEM(typ, lvl, ctx) LogItem li(typ, lvl, ctx)

#define MESSAGELI(sev, msg) \
{   LogItem li(Log::MessageOnly, sev, CODECONTEXT()); \
    li.set(AText(msg)); \
    LOG->enqueue(li); }

#define ASSERTLI(op, sev, bval) \
{   LOGITEM(Log::Assert, sev, CODECONTEXT()); \
    li.assertIs(op, bval, #bval); \
    LOG->enqueue(li); }

#define EXPECT2LI(op, sev, act) \
{   LOGITEM(Log::Expect, sev, CODECONTEXT()); \
        li.expect(op, act, #act); \
        LOG->enqueue(li); }

#define EXPECT4LI(op, sev, exp, act) \
{   LOGITEM(Log::Expect, sev, CODECONTEXT()); \
        li.expect(op, exp, #exp, act, #act); \
        LOG->enqueue(li); }

#define FORMATLI(sev, atxfmt, ai1, ai2, ai3, ai4)       \
    { LOGITEM(Log::Formatted, sev, CODECONTEXT());      \
    li.set(0, atxfmt), li.set(1, ai1), li.set(2, ai2),  \
    li.set(3, ai3), li.set(4, ai4);                     \
    LOG->enqueue(li); }                                 \

