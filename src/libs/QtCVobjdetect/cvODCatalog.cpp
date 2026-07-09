#include "cvODCatalog.h"

#include <QCoreApplication>

#include <Log.h>

cvODCatalog::cvODCatalog(QObject *parent) : QObject{parent} { clear(); }
cvODCatalog::cvODCatalog(const Url &url, QObject *parent)
    : QObject{parent}  { set(url); }
cvODCatalog::cvODCatalog(const QString &url, QObject *parent)
    : QObject{parent}  { set(url); }

void cvODCatalog::clear()
{
    FNENTER();
    mUrl.clear();
    mEntryMap.clear();
    FNEMIT(urlSet);
    emit urlSet(mUrl);
    mFileInfo.clear();
}

void cvODCatalog::set(const Url &aUrl)
{
    FNENTER();
    FNARG(aUrl);
    mUrl = aUrl;
    const int ln = FNEMIT(urlSet);
    FNEMITARG(ln, mUrl);
    emit urlSet(mUrl);
    if (mUrl.isLocalFile())
    {
        const QString cFilePath = mUrl.localFllePath();
        DUMPVAR(cFilePath);
        mFileInfo.setFile(QDir::current(), cFilePath);
    }
    DUMPVAR(fileInfo());
}

void cvODCatalog::set(const QString &aUrlString)
{
    FNENTER();
    FNARG(aUrlString);
    mUrl.set(aUrlString);
    emit urlSet(mUrl);
    if (mUrl.isLocalFile())
    {
        const QString cFilePath = mUrl.localFllePath();
        DUMPVAR(cFilePath);
        mFileInfo.setFile(QDir::current(), cFilePath);
    }
    DUMPVAR(fileInfo());
}

Status cvODCatalog::read()
{
    FNENTER()
    Status status;
    if (fileInfo())
    {
        QVariant tVar;
        tVar.setValue<Url>(url());
        status.set(StatusLevel::Error,
                   AText::format("Only Supporting Local Files: url=%1", tVar));
    }
    if (status.notError())
    {
        DUMPVAR(fileInfo().absoluteFilePath());
        if ( ! mXmlDocument.set(fileInfo()))
            status.set(StatusLevel::Error, AText::format("File does Not Exist: %1",
                        QVariant(fileInfo())));
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

cvODCatalog::EntryList cvODCatalog::list(const cvODObjectClass cls, const cvODResourceType type)
{
    //MUSTDO();
    Q_UNUSED(cls); Q_UNUSED(type);
    return EntryList();
}


