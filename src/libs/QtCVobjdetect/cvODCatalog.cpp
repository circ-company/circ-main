#include "cvODCatalog.h"

#include <Log.h>

cvODCatalog::cvODCatalog(QObject *parent) : QObject{parent} { clear(); }
cvODCatalog::cvODCatalog(const Url &url, QObject *parent) : QObject{parent}  { set(url); }
cvODCatalog::cvODCatalog(const QString &url, QObject *parent) : QObject{parent}  { set(url); }

void cvODCatalog::clear()
{
    FNENTER();
    mUrl.clear();
    mEntryMap.clear();
    FNEMIT(urlSet);
    emit urlSet(mUrl);
}

void cvODCatalog::set(const Url &url)
{
    mUrl = url;
    emit urlSet(mUrl);
}

void cvODCatalog::set(const QString &url)
{
    mUrl.set(url);
    emit urlSet(mUrl);
}

void cvODCatalog::read()
{
    MUSTDO();

}

void cvODCatalog::parse()
{
    MUSTDO();

}

cvODCatalog::EntryList cvODCatalog::list(const cvODClass cls, const cvODType type)
{
    MUSTDO();
    Q_UNUSED(cls); Q_UNUSED(type);
    return EntryList();
}


