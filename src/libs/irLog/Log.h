#pragma once

#include <QVariant>

#include <CodeContext.h>
#include <ArgumentInfo.h>
#include <ArgumentInfoList.h>
#include <StatusLevel.h>

#include "LogEngine.h"
#include "LogMacros.h"

#define FNENTER() LogFunction logFunction(CODECONTEXT());
#define FNARG(arg) QVariant qv=QVariant::fromValue(arg); \
            logFunction.addArgument(ArgumentInfo(#arg, #arg, qv));
#define FNARG2(arg1, arg2) \
            QVariant qv1=QVariant::fromValue(arg1); \
            QVariant qv2=QVariant::fromValue(arg2); \
            logFunction.addArgument(ArgumentInfo(#arg1, #arg1, qv1)); \
            logFunction.addArgument(ArgumentInfo(#arg2, #arg2, qv2));
#define FNARGD(arg, def) QVariant qv=QVariant::fromValue(arg); \
            logFunction.add(ArgumentInfo(#arg, #arg, qv, #def, def));
#define FNEMIT(sig) logFunction.emitSignal(__LINE__, #sig);
#define FNEMITARG(ln, arg) logFunction.emitArgument(ln, \
            ArgumentInfo(#arg, #arg, QVariant::fromValue(arg)));
#define FNRTNVOID() logFunction.returnVoid();
#define FNRETURN(rvar)  QVariant qvrvar=QVariant::fromValue(rvar); \
            logFunction.returnValue(ArgumentInfo(#rvar, #rvar, qvrvar))
#define NEWOBJ(ptr, obj, par) \
            { LOGITEM(Log::Malloc, StatusLevel::MAlloc, CODECONTEXT()); \
              li.newobj(ptr, #ptr, #obj, par, #par); LOG->enqueue(li); }

#define PROGMSG(msg)        MESSAGELI(StatusLevel::Progress, msg);

#define WEXPECT2(op, act) EXPECT2LI(op, StatusLevel::WExpect, act);
#define WEXPECT4(op, exp, act) EXPECT4LI(op, StatusLevel::WExpect, exp, act);

#define TASSERT(bval)       ASSERTLI(Log::True, StatusLevel::TAssert, bval);
#define WASSERT(bval)       ASSERTLI(Log::True, StatusLevel::WAssert, bval);
#define MUSTDO()            ASSERTLI(Log::False, StatusLevel::MustDo, true);
#define ASSERT(bval)        ASSERTLI(Log::True, StatusLevel::Assert, bval);
#define PASSERT(bval)       ASSERTLI(Log::True, StatusLevel::Process, bval);
#define MASSERT(bval)       ASSERTLI(Log::True, StatusLevel::MAlloc, bval);
#define SASSERT(bval)       ASSERTLI(Log::True, StatusLevel::System, bval);

#define STATUS(sts) LOGITEM(Log::MessageOnly, sts.level(), CODECONTEXT()); \
            li.set(sts.toString()); LOG->enqueue(li);

#define TDETAIL4(fmt, v1, v2, v3, v4)                       \
        FORMATLI(StatusLevel::TDetail,                      \
            ArgumentInfo(#fmt,QVariant(AText(fmt))),        \
            ArgumentInfo(#v1, QVariant::fromValue(v1)),     \
            ArgumentInfo(#v2, QVariant::fromValue(v2)),     \
            ArgumentInfo(#v3, QVariant::fromValue(v3)),     \
            ArgumentInfo(#v4, QVariant::fromValue(v4)));    \

#define TRACE2(fmt, v1, v2)                                 \
        FORMATLI(StatusLevel::TraceMsg,                     \
            ArgumentInfo(#fmt,QVariant(AText(fmt))),        \
            ArgumentInfo(#v1, QVariant::fromValue(v1)),     \
            ArgumentInfo(#v2, QVariant::fromValue(v2)),     \
            ArgumentInfo(), ArgumentInfo());                \


