#pragma once
#include "QtCVobjdetect.h"

#include <Enumeration.h>

#define CVODCLASS_ENUM(NV) \
    NV($nullClass, = 0)  \
    NV(FaceFrontal,)   \
    NV(FaceFrontalFull,)   \
    NV(EitherEye,)   \
    NV($maxClass,)
// TODO Profile, Body, Vehicle, Cat, Dog, LP

class QTCVOBJDETECT_EXPORT cvODClass : public Enumeration
{
public:
    DECLARE_ENUMERATION(cvODClass, CVODCLASS_ENUM)
};
