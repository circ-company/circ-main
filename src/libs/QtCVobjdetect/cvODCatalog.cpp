#include "cvODCatalog.h"

#include <QCoreApplication>

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
    {
        mFileInfo.setFile(qApp->arguments().first());
        mFileInfo.setFile(mUrl.localFllePath());
    }
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
    FNENTER()
    Status status;
    if (fileInfo().isNull())
    {
        QVariant tVar;
        tVar.setValue<Url>(url());
        status.set(StatusLevel::Error,
                   AText::format("Only Supporting Local Files: url=%1", tVar));
    }
    if (status.notError())
    {
        if ( ! mXmlDocument.set(fileInfo()))
        {
            status.set(StatusLevel::Error,
                       AText::format("Local File is Not Readable: %1",
                            fileInfo().filePath()));
        }
    }
    if (status.notError())
    {
        status = mXmlDocument.open(QIODevice::ReadOnly | QIODevice::ExistingOnly);
    }
    if (status.notError())
    {
        status = mXmlDocument.read();
    }
    if (status.isNull())
        status.level(StatusLevel::Progress);
    STATUS(status);
    return status;
}

Status cvODCatalog::parse()
{
    FNENTER()
    Status status;
    status = mXmlDocument.read();
    if (status.notError())
    {
        if ("ODCatalog" != mXmlDocument.rootTag())
        {
            status.set(StatusLevel::Error, "Expected RootElement `ODCatalog`: "
                                           "tag=%1 file=%2", QVariantList()
                           << mXmlDocument.rootTag()
                           << mFileInfo.filePath());
        }
    }
    if (status.notError())
    {

    }
    STATUS(status);
    return status;
}

cvODCatalog::EntryList cvODCatalog::list(const cvODClass cls, const cvODType type)
{
    //MUSTDO();
    Q_UNUSED(cls); Q_UNUSED(type);
    return EntryList();
}


