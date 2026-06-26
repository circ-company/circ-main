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
    mFileInfo.clear();
}

void cvODCatalog::set(const Url &url)
{
    mUrl = url;
    emit urlSet(mUrl);
    if (mUrl.isLocalFile())
        mFileInfo = mUrl.localFlleInfo();
}

void cvODCatalog::set(const QString &url)
{
    mUrl.set(url);
    emit urlSet(mUrl);
    if (mUrl.isLocalFile())
        mFileInfo = mUrl.localFlleInfo();
}

Status cvODCatalog::read()
{
    Status status;
    if (fileInfo().isNull())
    {
        status.set(StatusLevel::Error,
                   AText::formatted("Only Supporting Local Files: url=%1",
                        QVariantList() << QVariant::fromValue(url())));
        STATUS(status);
        return status;                                          /*/=====\*/
    }
    if ( ! mXmlDocument.set(fileInfo()))
    {
        status.set(StatusLevel::Error,
                   AText::formatted("Local File Does Not Readable: %1",
                        QVariantList() << QVariant(fileInfo().filePath())));
        STATUS(status);
        return status;                                          /*/=====\*/
    }
    status = mXmlDocument.read();
    STATUS(status);
    return status;
}

Status cvODCatalog::parse()
{
    Status status;

    STATUS(status);
    return status;
}

cvODCatalog::EntryList cvODCatalog::list(const cvODClass cls, const cvODType type)
{
    //MUSTDO();
    Q_UNUSED(cls); Q_UNUSED(type);
    return EntryList();
}


