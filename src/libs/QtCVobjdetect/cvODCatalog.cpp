#include "cvODCatalog.h"

#include <QCoreApplication>

#include <Log.h>

cvODCatalog::cvODCatalog(QObject *parent) : QObject{parent} { clear(); }
cvODCatalog::cvODCatalog(const FileInfo &aFI, QObject *parent)
    : QObject{parent}  { set(aFI); }


void cvODCatalog::clear()
{
    FNENTER();
    mEntryMap.clear();
    mFileInfo.clear();
}

void cvODCatalog::read()
{
    FNENTER();
    XmlDocObject tXDO(fileInfo(), this);
    mFileMap = tXDO.map();
}

void cvODCatalog::injest()
{
    FNENTER();
    mFileMap.enterGroup("ODCatalog");
    const KeyList cTypeList = mFileMap.levelKeys(1);
    foreach (const Key cTypeKey, cTypeList)
        injest(cTypeKey.last());
    mFileMap.clearGroup();
}

void cvODCatalog::injest(const KeySeg aType)
{
    FNENTER();
    mFileMap.enterGroup(aType);

    mFileMap.leaveGroup();
    MUSTDO(); // TODO: cvODCatalog::injest()
}

#if 0
Status cvODCatalog::read()
{
    FNENTER()
    Status status;
    if (fileInfo().null())
    {
        QVariant tVar;
        status.set(StatusLevel::Warning, "File Not Specified");
        return status;                                          /*/====\*/
    }
    if (status.level().isNull())
    {
        DUMPVAR(fileInfo().absoluteFilePath());
        if ( ! mXmlDocument.set(fileInfo()))
            status.set(StatusLevel::Error, AText::format("File does Not Exist: %1",
                        QVariant(fileInfo())));
    }
    if (status.level().notError())
    {
        status = mXmlDocument.open(QIODevice::ReadOnly | QIODevice::ExistingOnly);
    }
    if (status.level().notError())
    {
        status = mXmlDocument.read();
    }
    if (status.level().isNull())
        status.level(StatusLevel::Progress);
    STATUS(status);
    return status;
}

Status cvODCatalog::parse()
{
    FNENTER()
    Status status;
    status = mXmlDocument.read();
    if (status.level().notError())
    {
        if ("ODCatalog" != mXmlDocument.rootTag())
        {
            status.set(StatusLevel::Error,
                AText::format("Expected RootElement `ODCatalog`: tag=%1 file=%2",
                   mXmlDocument.rootTag(), mFileInfo.filePath()));
        }
    }
    if (status.level().notError())
    {

    }
    STATUS(status);
    return status;
}
#endif
cvODCatalog::EntryList cvODCatalog::list(const cvODObjectClass cls, const cvODResourceType type)
{
    //MUSTDO();
    Q_UNUSED(cls); Q_UNUSED(type);
    return EntryList();
}


