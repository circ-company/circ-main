#pragma once
#include "QtCVobjdetect.h"

#include <Enumeration.h>

#define CVODTYPE_ENUM(NV) \
    NV($nullType, = 0)  \
    NV(HaarCascade,)   \
    NV(HogDetector,)   \
    NV(BarcodeDetector,)   \
    NV(QrCodeDetector,)   \
    NV(DnnFaceDetector,)   \
    NV(ArUcoMarker,)   \
    NV($maxType,)

class QTCVOBJDETECT_EXPORT cvODResourceType : public Enumeration
{
    DECLARE_ENUMERATION(cvODResourceType, CVODTYPE_ENUM)
};

