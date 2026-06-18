#pragma once
#include "QtCVobjdetect.h"

#include <QSharedData>
#include <QVariant>

#include <DataProperty.h>
#include <KeySeg.h>

#include "cvODClass.h"
#include "cvODType.h"

#define CVODRESOURCE_DATAPROPS(TND) \
    TND(int, Type, 0) \
    TND(int, Class, 0) \
    TND(KeySeg, Name, KeySeg()) \
    TND(QMetaType, MetaType, QMetaType()) \
    TND(QVariant, Variant, QVariant()) \

class cvODResourceData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(CVODRESOURCE_DATAPROPS);
public:
    cvODResourceData(void)
    {
        DEFINE_DATAPROPS_CTORS(CVODRESOURCE_DATAPROPS);
    }
};

class QTCVOBJDETECT_EXPORT cvODResource
{
    DECLARE_PARENT_DATAPROPS(CVODRESOURCE_DATAPROPS)
    DECLARE_DATAPROPS(cvODResource, cvODResourceData)
public:
    cvODType type() const;
    cvODClass klass() const;
};
