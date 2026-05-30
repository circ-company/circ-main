#pragma once

#include "Enumeration.h"

#define SEVERITY_ENUM(NV) \
    NV($null, = 0)  \
    NV($Trace,)         /* 1-Begin Trace*/  \
    NV(DumpVar,)        /* 2*/  \
    NV(QObjectDump,)    /* 3*/  \
    NV(TraceMsg,)       /* 4*/  \
    NV(FuncEnter,)      /* 5*/  \
    NV(FuncArg,)        /* 6*/  \
    NV(FuncLeave,)      /* 7*/  \
    NV(TExpect,)        /* 8*/  \
    NV(TAssert,)        /* 9*/  \
    NV($Info,)          /*10-Begin Info*/  \
    NV(Detail,)         /*11*/ \
    NV(Info,)           /*12*/ \
    NV(Severity13,)   \
    NV(Progress,)       /*14*/  \
    NV(Severity15,)   \
    NV(StartUp,)        /*16*/  \
    NV($Warn,)          /*17-Begin Warn*/ \
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
