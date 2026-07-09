#include "cvODCatalogEntry.h"

DEFINE_DATAPROPS(cvODCatalogEntry, cvODCatalogEntryData)

void cvODCatalogEntry::ctor() {;}

void cvODCatalogEntry::dtor() {;}

cvODResourceType cvODCatalogEntry::odType() const
{
    return cvODResourceType(Type());
}

cvODObjectClass cvODCatalogEntry::odClass() const
{
    return cvODObjectClass(Class());
}
