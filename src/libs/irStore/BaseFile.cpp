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

BaseFile::~BaseFile()
{
    close();
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
    if (aMode)
    {
        set(aMode);
    }
    QIODeviceBase::OpenMode tOpenMode = mode();
    const bool cOK = pFile->open(tOpenMode);
    WEXPECT2(Log::True, pFile->open(tOpenMode));
    WEXPECT2(Log::True, pFile->openMode() == tOpenMode);
    if (cOK && pFile->isOpen() && pFile->openMode() == tOpenMode)
    {
        mOpenMode = tOpenMode;
        mpFile = pFile;
        return true;
    }
    else
    {
        error(pFile->errorString());
        return false;
    }
}

void BaseFile::close()
{
    FNENTER();
    clearError();
    mCurrentMode = QIODevice::NotOpen;
    if (mpFile)
    {
        mpFile->close();
        mpFile->deleteLater();
        mpFile = nullptr;
    }
    FNEMIT(closed);
    emit closed(fileInfo());
    FNRTNVOID();
}

bool BaseFile::read()
{
    TriBool result;
    FNENTER();
    DUMPVAR(fileInfo());
    DUMPVAR(fileMode());
    if (isOpen())
        if (file()->isReadable())
        {
            mBytes = file()->readAll();
            result = mBytes.length() == file()->size();
        }
    FNRETURN(result);
    return result;
}

bool BaseFile::write()
{
    FNENTER();
    Q_ASSERT(!"Finished"); // TODO
    return false;
}









