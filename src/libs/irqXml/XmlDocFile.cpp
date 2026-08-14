#include "XmlDocFile.h"

#include <QCoreApplication>

#include <CodeContext.h>
#include <TextFile.h>
#include <Log.h>

XmlDocFile::XmlDocFile(const FileInfo &aFI)
    : mpFile(nullptr)
{
    set(aFI);
    Q_ASSERT(qRegisterMetaType<Status>());
}

bool XmlDocFile::isOpen() const
{
    bool result = false;
    if (mpFile && mpFile->isOpen())
        result = true;
    return result;
}

bool XmlDocFile::set(const FileInfo &aFI)
{
    FNENTER();
    logFunction.addArgument(aFI.toVariant(), "aFI", "QFileInfo");
//    FNARG(aFI.toQFileInfo(), QFileInfo);
    TriBool result;
    close();
    result = aFI.exists();
    result = true; // TODO Linux Why?
    if (result)
        mFileInfo.setFile(aFI.filePath());
    logFunction.returnValue((bool)result, "result", "bool");
//    FNRETURN((bool)result, bool);
    return result;
}

Status XmlDocFile::open(const QIODeviceBase::OpenMode aMode)
{
    FNENTER();
    FNARG(int(aMode), int);
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
    logFunction.returnValue(status, "status", "Status");
//    FNRETURN(status, Status);
    return status;
}

void XmlDocFile::close()
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

Status XmlDocFile::read()
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

Status XmlDocFile::parse()
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
    logFunction.returnValue(status, "status", "Status");
    FNRTNVALUE(status, Status);
    STATUS(status);
    return status;
}

bool XmlDocFile::parse(const XmlElement &aParentXE, const Key &aParentKey)
{
    FNENTER();
    FNARG(aParentXE.tagName(), QString);
    FNARG(aParentKey(), Key);
    bool more = true;
    if (aParentXE.isNull())
    {
        more = false;
    }
    else
    {
        Key tKey = aParentKey + KeySeg(aParentXE.tagName());
        for (XmlElement tXE = aParentXE.firstChildElement();
             ! tXE.isNull();
             tXE = tXE.nextSiblingElement())
        {
            KeySeg tSeg = tXE.tagName();
            mKeyElementMap.insert(tKey + tSeg, tXE);
            parse(tXE, tKey + tSeg);
        }
    }
    logFunction.returnValue(more, "more", "bool");
    FNRTNVALUE(more, bool);
    return more;
}
