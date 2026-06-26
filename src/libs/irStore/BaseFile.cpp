#include "BaseFile.h"

#include <QFile>

#include <FileInfo.h>
#include <Log.h>

BaseFile::BaseFile(QObject *parent)
    : QObject(parent)
    , mFileInfo(true) // null is true
    , mOpenMode(QIODevice::NotOpen)
    , mpFile(nullptr)
{
    setObjectName("BaseFile:Null");
}

BaseFile::BaseFile(const FileInfo &aFI,
                   const QIODeviceBase::OpenMode mode,
                   QObject *parent)
    : QObject(parent)
    , mFileInfo(aFI)
    , mOpenMode(mode)
    , mpFile(nullptr)
{
    setObjectName("BaseFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
}

BaseFile::BaseFile(const FSText &aFName,
                   const QIODeviceBase::OpenMode mode,
                   QObject *parent)
    : QObject(parent)
    , mFileInfo(aFName)
    , mOpenMode(mode)
    , mpFile(nullptr)
{
    setObjectName("BaseFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
}

void BaseFile::set(const FileInfo &aFI)
{
    FNENTER();
    FNARG(aFI);
    mFileInfo = aFI;
    emit infoSet(mFileInfo, mFileInfo.exists());
    const int el = FNEMIT(infoSet);
    FNEMITARG(el, mFileInfo);
    FNEMITARG(el, mFileInfo.exists());
    FNRTNVOID();
}

void BaseFile::set(const FSText &aFileName)
{
    set(FileInfo(aFileName));
}

bool BaseFile::open(const QIODeviceBase::OpenMode aMode)
{
    FNENTER();
    FNARG(aMode);
    close();
    QFile * pFile = new QFile(fileInfo().filePath(), this);
    NEWOBJ(pFile, QFile, this);
    if (pFile->isOpen() && pFile->openMode() == aMode)
    {
        mOpenMode = aMode;
        mpFile = pFile;
        return true;
    }
    else
    {
        WEXPECT2(Log::True, pFile->open(aMode));
        WEXPECT2(Log::True, pFile->openMode() == aMode);
        return false;
    }
}

void BaseFile::close()
{
    FNENTER();
    Q_ASSERT(!"Finished"); // TODO

    FNRTNVOID();
}

bool BaseFile::read()
{
    FNENTER();
    Q_ASSERT(!"Finished"); // TODO
    return false;
}

bool BaseFile::write()
{
    FNENTER();
    Q_ASSERT(!"Finished"); // TODO

    return false;
}








