#pragma once

#include <QSharedDataPointer>
#include <DataProperty.h>

#include <QDomElement>
#include <QFileInfo>
#include <QList>

#include <CText.h>
#include <Id.h>
#include <Size.h>
#include <Url.h>

#include "cvODObjectClass.h"
#include "cvODResourceType.h"

#define CVODCATALOGENTRY_DATAPROPS(TND) \
    TND(Id, EntryId, Id()) \
    TND(int, Class, 0) \
    TND(int, Type, 0) \
    TND(bool, IsDefault, false) \
    TND(Size, CellSize, Size()) \
    TND(Url, ResourceUrl, Url()) \


class cvODCatalogEntryData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(CVODCATALOGENTRY_DATAPROPS);
public:
    cvODCatalogEntryData(void)
    {
        DEFINE_DATAPROPS_CTORS(CVODCATALOGENTRY_DATAPROPS);
    }
};

class QTCVOBJDETECT_EXPORT cvODCatalogEntry
{
    DECLARE_PARENT_DATAPROPS(CVODCATALOGENTRY_DATAPROPS)
    DECLARE_DATAPROPS(cvODCatalogEntry, cvODCatalogEntryData)
public: // types
    typedef QList<cvODCatalogEntry> List;

public: // const
    cvODResourceType odType() const;
    cvODObjectClass odClass() const;
};
