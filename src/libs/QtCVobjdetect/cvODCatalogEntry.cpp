#include "cvODCatalogEntry.h"

DEFINE_DATAPROPS(cvODCatalogEntry, cvODCatalogEntryData)


cvODType cvODCatalogEntry::odType() const
{
    return cvODType(Type());
}

cvODClass cvODCatalogEntry::odClass() const
{
    return cvODClass(Class());
}
