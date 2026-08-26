#pragma once

#include <QVariant>

#include <CodeContext.h>
#include <StatusLevel.h>

#include "LogClass.h"
#include "LogMacros.h"

#define FNENTER() LogFunction logFunction(CODECONTEXT());
#define FNARG(arg, T) { /* QVariant qv; qv.setValue<T>(arg);*/ \
            logFunction.addArgument(arg, #arg, #T); }
#define FNEMIT(sig) logFunction.emitSignal(#sig);
#define FNEMITARG(sig, arg, T) logFunction.emitArgument(sig, arg, #arg, T);
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

#define CONNECT(sobj, sig, robj, slt) \
          { LOGITEM(Log::Connect, StatusLevel::Error, CODECONTEXT()); \
            li.connect(sobj, QMetaMethod::fromSignal(sig), \
            robj, QMetaMethod::fromSignal(slt), #sobj, #sig, #robj, #slt); \
            LOG->enqueue(li); }

#define STARTMSG(msg)       MESSAGELI(StatusLevel::Start, msg);
#define TRACE(msg)          MESSAGELI(StatusLevel::Trace, msg);
#define DETAIL(msg)         MESSAGELI(StatusLevel::Detail, msg);
#define INFO(msg)           MESSAGELI(StatusLevel::Info, msg);
#define PROGRESS(msg)       MESSAGELI(StatusLevel::Progress, msg);
#define EXITMSG(msg)        MESSAGELI(StatusLevel::Exit, msg);
#define WARNING(msg)        MESSAGELI(StatusLevel::Warning, msg);
#define WHATDO(msg)         MESSAGELI(StatusLevel::WhatDo, msg);
#define ERRMSG(msg)         MESSAGELI(StatusLevel::Error, msg);
#define NEEDDO(msg)         MESSAGELI(StatusLevel::NeedDo, msg);
#define FAULTMSG(msg)       MESSAGELI(StatusLevel::Fault, msg);
#define MUSTDO(msg)         MESSAGELI(StatusLevel::MustDo, msg);


#define TEXPECTIS(act)      EXPECT2LI(Log::Is, StatusLevel::TExpect, act);
#define TEXPECTNOT(act)     EXPECT2LI(Log::Not, StatusLevel::TExpect, act);

#define WEXPECTIS(act)      EXPECT2LI(Log::Is, StatusLevel::WExpect, act);
#define WEXPECTNOT(act)     EXPECT2LI(Log::Not, StatusLevel::WExpect, act);
#define WEXPECT(op, exp, act) EXPECT4LI(op, StatusLevel::WExpect, exp, act);
#define WEXPECTEQ(exp, act) EXPECT4LI(Log::Equal, StatusLevel::WExpect, exp, act);
#define WEXPECTNE(exp, act) EXPECT4LI(Log::NotEqual, StatusLevel::WExpect, exp, act);

#define EXPECTIS(act)       ASSERTLI(Log::True, StatusLevel::Expect, act);
#define EXPECTNOT(act)      ASSERTLI(Log::False, StatusLevel::Expect, act);

#define WCKPOINTER(ptr)     CHECKPTR(StatusLevel::WNullPtr, ptr);
#define CKPOINTER(ptr)      CHECKPTR(StatusLevel::NullPtr, ptr);

#define TASSERT(bval)       ASSERTLI(Log::True, StatusLevel::TAssert, bval);
#define WASSERT(bval)       ASSERTLI(Log::True, StatusLevel::WAssert, bval);
#define ASSERT(bval)        ASSERTLI(Log::True, StatusLevel::Assert, bval);
#define PASSERT(bval)       ASSERTLI(Log::True, StatusLevel::Process, bval);
#define MASSERT(bval)       ASSERTLI(Log::True, StatusLevel::MAlloc, bval);
#define SASSERT(bval)       ASSERTLI(Log::True, StatusLevel::System, bval);

#define STATUS(sts) LOGITEM(Log::MessageOnly, sts.level(), CODECONTEXT()); \
            li.set(sts.message()); LOG->enqueue(li); DUMPQSL(sts.notes());
