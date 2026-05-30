#pragma once

#include "Enumeration.h"

#define SEVERITY_ENUM(NV) \
    NV($null, = 0)  \
    NV($Trace,)         /* 1-Begin Trace*/  \
    NV(DumpVar,)        /* 2*/  \
    NV(QObjectDump,)    /* 3*/  \
    NV(TDetail,)        /* 4*/  \
    NV(TraceMsg,)       /* 5*/  \
    NV(TProgress,)      /* 6*/  \
    NV(FuncEnter,)      /* 7*/  \
    NV(FuncArg,)        /* 8*/  \
    NV(FuncLeave,)      /* 9*/  \
    NV(TExpect,)        /*10*/  \
    NV(TAssert,)        /*11*/  \
    NV($Info,)          /*12-Begin Info*/  \
    NV(Detail,)         /*13*/ \
    NV(Info,)           /*14*/ \
    NV(Progress,)       /*15*/  \
    NV(Exit,)           /*16*/  \
    NV(StartUp,)        /*17*/  \
    NV($Warn,)          /*18-Begin Warn*/ \
    NV(Prefer,)         /*19*/  \
    NV(Warning,)        /*20*/  \
    NV(WExpect,)        /*21*/  \
    NV(WAssert,)        /*22*/  \
    NV(WMemory,)        /*23*/  \
    NV($Error,)         /*24-Begin Error*/ \
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
