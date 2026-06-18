#include "cvODCatalogEntry.h"

DEFINE_DATAPROPS(cvODCatalogEntry, cvODCatalogEntryData)

void cvODCatalogEntry::ctor() {;}
void cvODCatalogEntry::dtor() {;}

cvODType cvODCatalogEntry::odType() const
{
    return cvODType(Type());
}

cvODClass cvODCatalogEntry::odClass() const
{
    return cvODClass(Class());
}
