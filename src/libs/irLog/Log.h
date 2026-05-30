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
