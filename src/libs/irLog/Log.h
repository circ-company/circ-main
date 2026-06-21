#pragma once

#include <QVariant>

#include <CodeContext.h>
#include <CodeValue.h>
#include <StatusLevel.h>

#include "LogEngine.h"
#include "LogMacros.h"

#define FNENTER() LogFunction logFunction(CODECONTEXT());
#define FNARG(arg) QVariant qv=QVariant::fromValue(arg); \
            logFunction.addArgument(CodeValue(qv, #arg));
#define FNARGD(arg, def) QVariant qv=QVariant::fromValue(arg); \
            logFunction.add(CodeValue(qv, #arg, def, #def));
#define FNEMIT(sig) logFunction.emitSignal(#sig);
#define FNLEAVE() logFunction.leave();
#define FNLEAVER(rvar) QVariant qvrvar=QVariant::fromValue(rvar); \
            logFunction.leave(CodeValue(qvrvar, #rvar))

#define PROGMSG(msg)        MESSAGELI(StatusLevel::Progress, msg);

#define TASSERT(bval)       ASSERTLI(Log::True, StatusLevel::TAssert, bval);
#define WASSERT(bval)       ASSERTLI(Log::True, StatusLevel::WAssert, bval);
#define MUSTDO()            ASSERTLI(Log::False, StatusLevel::MustDo, true);
#define ASSERT(bval)        ASSERTLI(Log::True, StatusLevel::Assert, bval);
#define PASSERT(bval)       ASSERTLI(Log::True, StatusLevel::Process, bval);
#define MASSERT(bval)       ASSERTLI(Log::True, StatusLevel::MAlloc, bval);
#define SASSERT(bval)       ASSERTLI(Log::True, StatusLevel::System, bval);

#define TDETAIL4(fmt, v1, v2, v3, v4) QVariant qvf(AText(fmt)); \
            QVariant qv1=QVariant::fromValue(v1); \
            QVariant qv2=QVariant::fromValue(v2); \
            QVariant qv3=QVariant::fromValue(v3); \
            QVariant qv4=QVariant::fromValue(v4); \
        FORMATLI(StatusLevel::TDetail,                     \
            CodeValue(qvf, #fmt),  \
            CodeValue(qv1, #v1),   \
            CodeValue(qv2, #v2),   \
            CodeValue(qv3, #v3),   \
            CodeValue(qv4, #v4));

#define TRACE2(fmt, v1, v2) { QVariant qvf(AText(fmt)); \
            QVariant qv1=QVariant::fromValue(v1);       \
            QVariant qv2=QVariant::fromValue(v2);       \
        FORMATLI(StatusLevel::TraceMsg,                    \
             CodeValue(qvf, #fmt), \
             CodeValue(qv1, #v1),  \
             CodeValue(qv2, #v2),  \
             CodeValue(), CodeValue()); }


