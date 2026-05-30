#pragma once

#include <QVariant>

#include <CodeContext.h>
#include <CodeValue.h>
#include <Severity.h>

#include "LogEngine.h"
#include "LogMacros.h"

#define FNENTER() LogFunction logFunction(CODECONTEXT());
#define FNARG(arg) QVariant qv=QVariant::fromValue(arg); \
            logFunction.add(Severity::FuncArg, CodeValue(CodeValue::Argument, qv, #arg));
#define FNVAR(var) QVariant qv=QVariant::fromValue(var); \
            logFunction.add(Severity::DumpVar, CodeValue(CodeValue::Variable, qv, #var));
#define FNLEAVE() logFunction.leave(CODECONTEXT());
#define FNRETURN(rvar) QVariant qv=QVariant::fromValue(rvar); \
            logFunction.leave(CodeValue(CodeValue::Variable, qv, #rvar))

#define PROGMSG(msg)        MESSAGELI(Severity::Progress, msg);
#define WEXPECT(exp, act)   EXPECTLI(Severity::Warning, exp, act);
