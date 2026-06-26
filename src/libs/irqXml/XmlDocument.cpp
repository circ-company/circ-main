#include "XmlDocument.h"

#include <QCoreApplication>

#include <CodeContext.h>
#include <TextFile.h>
#include <Log.h>

XmlDocument::XmlDocument(const FileInfo &aFI) { set(aFI); }

bool XmlDocument::isOpen() const
{
    bool result = false;
    if (mpFile && mpFile->isOpen())
        result = true;
    return result;
}

bool XmlDocument::set(const FileInfo &aFI)
{
    mFileInfo.setFile(aFI.filePath());
    return mFileInfo.exists() && mFileInfo.isReadable();
}

Status XmlDocument::open(const QIODeviceBase::OpenMode aMode)
{
    Status status;
    close();
    if ( ! mFileInfo.isReadable())
    {
        status.set(StatusLevel::Error, "Expected file %1 readable",
                   mFileInfo.filePath());
        return status;                                      /*/=====\*/
    }
    TextFile * pFile = new TextFile(mFileInfo, aMode, (QObject *)qApp);
    NEWOBJ(pFile, TextFile,  (QObject *)qApp);
    return status;
}

void XmlDocument::close()
{
    if (mpFile)
    {
        mpFile->close();
        mpFile->deleteLater();
        mpFile = nullptr;
    }
}

Status XmlDocument::read()
{
    Status status;

    return status;
}

Status XmlDocument::parse()
{
    Status status;
    mRootElement = documentElement();
    if ("ODCatalog" != mRootElement.tagName())
    {
        status.set(StatusLevel::Error, "Expected RootElement `ODCatalog`: "
                                       "tag=%1 file=%2", QVariantList()
                        << QVariant(mRootElement.tagName())
                        << QVariant(mFileInfo.filePath()));
    }
    return status;

}
