#pragma once

#include <QVariant>

#include <CodeContext.h>
#include <CodeValue.h>
#include <Severity.h>

#include "LogEngine.h"
#include "LogMacros.h"

#define FNENTER() LogFunction logFunction(CODECONTEXT());
#define FNARG(arg) QVariant qv=QVariant::fromValue(arg); \
            logFunction.add(CodeValue(CodeValue::Argument, qv, #arg));
#define FNLEAVE() logFunction.leave();
#define FNRETURN(rvar) QVariant qv=QVariant::fromValue(rvar); \
            logFunction.leave(CodeValue(CodeValue::Value, qv, #rvar))

#define PROGMSG(msg)        MESSAGELI(Severity::Progress, msg);

#define TASSERT(bval)       ASSERTLI(LogOperator::True, Severity::TAssert, bval);
#define WASSERT(bval)       ASSERTLI(LogOperator::True, Severity::Warning, bval);
#define ASSERT(bval)        ASSERTLI(LogOperator::True, Severity::Error, bval);
#define JASSERT(bval)       ASSERTLI(LogOperator::True, Severity::MajorError, bval);
#define PASSERT(bval)       ASSERTLI(LogOperator::True, Severity::ProcessFault, bval);
#define MASSERT(bval)       ASSERTLI(LogOperator::True, Severity::MemoryFault, bval);
#define SASSERT(bval)       ASSERTLI(LogOperator::True, Severity::SystemFault, bval);

#define TDETAIL4(fmt, v1, v2, v3, v4) QVariant qvf(AText(fmt)); \
            QVariant qv1=QVariant::fromValue(v1); \
            QVariant qv2=QVariant::fromValue(v2); \
            QVariant qv3=QVariant::fromValue(v3); \
            QVariant qv4=QVariant::fromValue(v4); \
        FORMATLI(Severity::TDetail,                     \
            CodeValue(CodeValue::Variable, qvf, #fmt),  \
            CodeValue(CodeValue::Variable, qv1, #v1),   \
            CodeValue(CodeValue::Variable, qv2, #v2),   \
            CodeValue(CodeValue::Variable, qv3, #v3),   \
            CodeValue(CodeValue::Variable, qv4, #v4));

#define TRACE2(fmt, v1, v2) { QVariant qvf(AText(fmt)); \
QVariant qv1=QVariant::fromValue(v1); \
    QVariant qv2=QVariant::fromValue(v2); \
    FORMATLI(Severity::TraceMsg,                     \
             CodeValue(CodeValue::Variable, qvf, #fmt),  \
             CodeValue(CodeValue::Variable, qv1, #v1),   \
             CodeValue(CodeValue::Variable, qv2, #v2),  \
             CodeValue(), CodeValue()); }


