#pragma once

#include "Enumeration.h"

#define SEVERITY_ENUM(NV) \
    NV($null, = 0)  \
    NV($Trace,)         /* 1-Begin Trace*/  \
    NV(DumpVar,)        /* 2*/  \
    NV(QObjectDump,)    /* 3*/  \
    NV(TraceMsg,)       /* 4*/  \
    NV(Severity05,)   \
    NV(Severity06,)   \
    NV(TExpect,)        /* 7*/  \
    NV(TAssert,)        /* 8*/  \
    NV($Info,)          /* 9-Begin Info*/  \
    NV(Detail,)         /*10*/ \
    NV(Severity11,)   \
    NV(Info,)           /*12*/ \
    NV(Severity13,)   \
    NV(Progress,)       /*14*/  \
    NV(Severity15,)   \
    NV(StartUp,)        /*16*/  \
    NV($Warning,)       /*17-Begin Warning*/ \
    NV(Prefer,)         /*18*/  \
    NV(Warning,)        /*19*/  \
    NV(WExpect,)        /*20*/  \
    NV(WAssert,)        /*21*/  \
    NV(WMemory,)        /*22*/  \
    NV($Error,)         /*23-Begin Error*/ \
    NV(MinorError,)     /*24*/  \
    NV(Error,)          /*25*/  \
    NV(MajorError,)     /*26*/  \
    NV($Fault,)         /*27-Begin Fault*/ \
    NV(ProcessFault,)   /*28*/  \
    NV(MemoryFault,)    /*29*/  \
    NV(SystemFault,)    /*30*/  \
    NV($max,)           /*31*/  \

class Severity : public Enumeration
{
    DECLARE_ENUMERATION(Severity, SEVERITY_ENUM)
};
