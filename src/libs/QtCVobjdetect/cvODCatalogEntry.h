#pragma once
#include "QtCVobjdetect.h"

#include <QSharedDataPointer>
#include <DataProperty.h>

#include <QDomElement>
#include <QFileInfo>

#include <CText.h>
#include <Key.h>
#include <List.h>
#include <MillisecondTime.h>
#include <Url.h>

#include "cvODClass.h"
#include "cvODType.h"

#define CVODCATALOGENTRY_DATAPROPS(TND) \
    TND(Url, EntryUrl, Url()) \
    TND(Milliseconds, TimeStamp, 0) \
    TND(int, Class, 0) \
    TND(int, Type, 0) \
    TND(bool, IsDefault, false) \
    TND(AText, Name, AText()) \
    TND(Key, EntryKey, Key()) \
    TND(Url, ResourceUrl, Url()) \
    TND(QFileInfo, ResourceFileInfo, QFileInfo()) \
    TND(QDomElement, ResourceRootDE, QDomElement()) \


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
    typedef ListT<cvODCatalogEntry> List;

public: // const
    cvODType odType() const;
    cvODClass odClass() const;
};
