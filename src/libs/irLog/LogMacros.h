#pragma once

#include <CodeContext.h>
#include <LogFunction.h>

#include "LogItem.h"
#include "LogEngine.h"

#define LOGITEM(typ, lvl, ctx) LogItem li(typ, lvl, ctx)

#define MESSAGELI(sev, msg) \
{   LogItem li(Log::MessageOnly, sev, CODECONTEXT()); \
    li.set(AText(msg)); \
    LOG->enqueue(li); }

#define ASSERTLI(op, sev, bval) \
{   LOGITEM(Log::Assert, sev, CODECONTEXT()); \
    li.assertIs(op, bval, #bval); \
    LOG->enqueue(li); if(li.isFault()) Q_ASSERT(false); }

#define EXPECT2LI(op, sev, act) \
{   LOGITEM(Log::Expect, sev, CODECONTEXT()); \
        li.expect(op, act, #act); \
        LOG->enqueue(li);  if(li.isFault()) Q_ASSERT(false); }

#define EXPECT4LI(op, sev, exp, act) \
{   LOGITEM(Log::Expect, sev, CODECONTEXT()); \
        li.expect(op, exp, #exp, act, #act); \
        LOG->enqueue(li);  if(li.isFault()) Q_ASSERT(false); }

