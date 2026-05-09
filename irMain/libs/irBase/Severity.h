#pragma once

#include "Enumeration.h"

#define SEVERITY_ENUM(NV) \
    NV($Null, = 0)  \
    NV(Minimum,)    /* 1*/  \
    NV(Severity02,)   \
    NV(Severity03,)   \
    NV(Severity04,)   \
    NV(Severity05,)   \
    NV(Severity06,)   \
    NV(Severity07,)   \
    NV(Severity08,)   \
    NV(Severity09,)   \
    NV(Severity10,)   \
    NV(Severity11,)   \
    NV(Severity12,)   \
    NV(Severity13,)   \
    NV(Severity14,)   \
    NV(Severity15,)   \
    NV(Severity16,)   \
    NV(Severity17,)   \
    NV(Severity18,)   \
    NV(Severity19,)   \
    NV(Severity20,)   \
    NV(Severity21,)   \
    NV(Severity22,)   \
    NV(Severity23,)   \
    NV(Severity24,)   \
    NV(Severity25,)   \
    NV(Severity26,)   \
    NV(Severity27,)   \
    NV(Severity28,)   \
    NV(Severity29,)   \
    NV(Severity30,)   \
    NV(Maximum,)    /*31*/   \

class Severity : public Enumeration
{
    DECLARE_ENUMERATION(Severity, SEVERITY_ENUM)
};
