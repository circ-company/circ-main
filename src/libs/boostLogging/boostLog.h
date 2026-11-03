#pragma once

#include "boostLogEngine.h"
#include "boostLogInternal.h"
#include "boostLogMacros.h"

Q_GLOBAL_STATIC(boostLogEngine, BLOGE);

#define BLFUNCTION  boostLogFunction(Q_FILE_INFO, __FILE__, __LINE__, BLOGE);

#define SHOULDNOT
