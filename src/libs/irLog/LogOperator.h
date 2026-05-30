#pragma once

#include <Enumeration.h>


#include <Enumeration.h>
#define LOGOPERATOR_ENUM(NV) \
    NV($null, = 0)  \
    NV(True,)   \
    NV(False,)   \
    NV(Not,)   \
    NV(Invert,)   \
    NV(Equal,)   \
    NV(NotEqual,)   \
    NV(Less,)   \
    NV(LessEqual,)   \
    NV(Greater,)   \
    NV(GreaterEqual,)   \
    NV($max,)   \

class LogOperator : public Enumeration
{
    DECLARE_ENUMERATION(LogOperator, LOGOPERATOR_ENUM)
};
