#include "XmlDocument.h"

#include <QCoreApplication>

#include <CodeContext.h>
#include <TextFile.h>
#include <Log.h>

XmlDocument::XmlDocument(const FileInfo &aFI) : mpFile(nullptr) { set(aFI); }

bool XmlDocument::isOpen() const
{
    bool result = false;
    if (mpFile && mpFile->isOpen())
        result = true;
    return result;
}

bool XmlDocument::set(const FileInfo &aFI)
{
    FNENTER();
    FNARG(aFI);
    close();
    TriBool result;
    result = aFI.exists();
    result = true; // TODO Linux Why?
    if (result)
        mFileInfo.setFile(aFI.filePath());
    FNRETURN((bool)result);
    return result;
}

Status XmlDocument::open(const QIODeviceBase::OpenMode aMode)
{
    FNENTER();
    FNARGT(aMode, int);
    DUMPVAR(mFileInfo);
    Status status;
    close();
    if (false) // TODO ! mFileInfo.isReadable())
    {
        status.set(StatusLevel::Error,
            AText::format("Expected file %1 readable",mFileInfo.filePath()));
    }
    TextFile * pTextFile=nullptr;
    if (status.level().notError())
    {
        pTextFile = new TextFile(mFileInfo, aMode, (QObject *)qApp);
        if ( ! pTextFile)
            status.set(StatusLevel::Error,
                       AText::format("Creating file object %1 failed: %2",
                   mFileInfo.filePath(), pTextFile->error()));
    }
    NEWOBJ(pTextFile, TextFile,  (QObject *)qApp);
    if (status.level().notError() && pTextFile)
    {
        if ( ! pTextFile->open())
            status.set(StatusLevel::Error,
                       AText::format("Open file %1 failed: %2",
                            mFileInfo.filePath(), pTextFile->error()));
    }
    if (status.level().notError())
        status.set(StatusLevel::Progress,
                   AText::format("%1 file opened", mFileInfo.toString()));
    STATUS(status);
    FNRETURN(status);
    return status;
}

void XmlDocument::close()
{
    FNENTER();
    if (mpFile)
    {
        mpFile->close();
        mpFile->deleteLater();
        mpFile = nullptr;
    }
    mFileInfo.clear();
    FNRTNVOID();
}

Status XmlDocument::read()
{
    FNENTER();
    Status status;
    Q_CHECK_PTR(mpFile);
    if ( ! mpFile->read())
    {
        status.set(StatusLevel::Error,
                   AText::format("Error reading %1: %2",
                        mFileInfo.toString(), mpFile->error()));
    }
    STATUS(status);
    return status;
}

Status XmlDocument::parse()
{
    FNENTER();
    Status status;
    setContent(mpFile->data());
    mRootElement = documentElement();
    if (rootElement().isNull())
    {
        status.set(StatusLevel::Error,
                   AText::format("XML File %1 is empty",
                        mFileInfo.toString()));
    }
    else
    {
        MUSTDO(); // TODO Iterate
    }
    FNRETURN(status);
    STATUS(status);
    return status;
}

bool XmlDocument::parse(const XmlElement &aParentXE, const Key &aParentKey)
{
    FNENTER();
    FNARG(aParentXE.tagName());
    FNARG(aParentKey());
    bool more = true;
    if (aParentXE.isNull())
    {
        more = false;
    }
    else
    {
        Key tKey = aParentKey + aParentXE.tagName();
        for (XmlElement tXE = aParentXE.firstChildElement();
             ! tXE.isNull();
             tXE = tXE.nextSiblingElement())
        {
            KeySeg tSeg = tXE.tagName();
            mKeyElementMap.insert(tKey + tSeg, tXE);
            parse(tXE, tKey + tSeg);
        }
    }
    FNRETURN(more);
    return more;
}
