#include "cvODCatalog.h"

cvODCatalog::cvODCatalog(QObject *parent) : QObject{parent} { clear(); }
cvODCatalog::cvODCatalog(const Url &url, QObject *parent) : QObject{parent}  { set(url); }
cvODCatalog::cvODCatalog(const QString &url, QObject *parent) : QObject{parent}  { set(url); }

void cvODCatalog::clear()
{
    mUrl.clear();
    mEntryMap.clear();
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

}

void cvODCatalog::parse()
{

}

cvODCatalog::EntryList cvODCatalog::list(const cvODClass cls, const cvODType type)
{
    return EntryList();
}


