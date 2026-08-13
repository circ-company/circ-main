#pragma once

#include <QVariant>

#include <CodeContext.h>
#include <StatusLevel.h>

#include "LogEngine.h"
#include "LogMacros.h"

#define FNENTER() LogFunction logFunction(CODECONTEXT());
#define FNARG(arg, T) { /* QVariant qv; qv.setValue<T>(arg);*/ \
            logFunction.addArgument(arg, #arg, #T); }
#define FNEMIT(sig) logFunction.emitSignal(#sig);
#define FNEMITARG(sig, arg, T) logFunction.emitArgument(sig, arg, #arg, #T);
#define FNRTNVOID() logFunction.returnVoid();
#define FNRTNVALUE(rvar, T) logFunction.returnValue(rvar, #rvar, #T);

#define NEWOBJ(ptr, obj, par) \
          { LOGITEM(Log::Malloc, StatusLevel::MAlloc, CODECONTEXT()); \
            li.newobj(ptr, #obj, par); LOG->enqueue(li); }

#define DUMPVAR(var)   \
          { LOGITEM(Log::Dump, StatusLevel::DumpVar, CODECONTEXT()); \
            li.dumpVar(var, #var); LOG->enqueue(li); }
#define DUMPVART(var, T)   \
          { LOGITEM(Log::Dump, StatusLevel::DumpVar, CODECONTEXT()); \
            QVariant qv; qv.setValue<T>(var); \
            li.dumpVar(qv, #var); LOG->enqueue(li); }
#define DUMPQSL(qsl) { foreach(const QString cSt, qsl) qInfo() << cSt; }
#define DUMPQBAL(qbal) { foreach(const QByteArray cBA, qbal) qInfo() << cBA; }

#define TRACEMSG(msg)       MESSAGELI(StatusLevel::Trace, msg);
#define INFOMSG(msg)        MESSAGELI(StatusLevel::Info, msg);
#define PROGMSG(msg)        MESSAGELI(StatusLevel::Progress, msg);
#define WARNMSG(msg)        MESSAGELI(StatusLevel::Warning, msg);

#define TEXPECTIS(act)      EXPECT2LI(Log::Is, StatusLevel::TExpect, act);
#define TEXPECTNOT(act)     EXPECT2LI(Log::Not, StatusLevel::TExpect, act);
#define WEXPECTIS(act)      EXPECT2LI(Log::Is, StatusLevel::WExpect, act);
#define WEXPECTNOT(act)     EXPECT2LI(Log::Not, StatusLevel::WExpect, act);

#define WEXPECT(op, exp, act) EXPECT4LI(op, StatusLevel::WExpect, exp, act);
#define WEXPECTEQ(exp, act) EXPECT4LI(Log::Equal, StatusLevel::WExpect, exp, act);
#define WEXPECTNE(exp, act) EXPECT4LI(Log::NotEqual, StatusLevel::WExpect, exp, act);

#define EXPECTIS(act)       ASSERTLI(Log::True, StatusLevel::Expect, act);
#define EXPECTNOT(act)      ASSERTLI(Log::False, StatusLevel::Expect, act);
#define TASSERT(bval)       ASSERTLI(Log::True, StatusLevel::TAssert, bval);
#define WASSERT(bval)       ASSERTLI(Log::True, StatusLevel::WAssert, bval);
#define MUSTDO()            ASSERTLI(Log::False, StatusLevel::MustDo, true);
#define WASSERT(bval)       ASSERTLI(Log::True, StatusLevel::WAssert, bval);
#define ASSERT(bval)        ASSERTLI(Log::True, StatusLevel::Assert, bval);
#define PASSERT(bval)       ASSERTLI(Log::True, StatusLevel::Process, bval);
#define MASSERT(bval)       ASSERTLI(Log::True, StatusLevel::MAlloc, bval);
#define SASSERT(bval)       ASSERTLI(Log::True, StatusLevel::System, bval);

#define STATUS(sts) LOGITEM(Log::MessageOnly, sts.level(), CODECONTEXT()); \
            li.set(sts.message()); LOG->enqueue(li); DUMPQSL(sts.notes());
