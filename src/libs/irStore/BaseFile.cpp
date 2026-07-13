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
                   const Mode mode,
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
                   const Mode mode,
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
    FNEMITARG(infoSet, mFileInfo);
    FNEMITARG(infoSet, mFileInfo.exists());
    FNRTNVOID();
}

void BaseFile::set(const FSText &aFileName)
{
    set(FileInfo(aFileName));
}

bool BaseFile::open(const Mode aMode)
{
    FNENTER();
    FNARGT(aMode, int);
    close();
    QFile * pFile = new QFile(fileInfo().filePath(), this);
    NEWOBJ(pFile, QFile, this);
    if (aMode) set(aMode);
    Mode tOpenMode = mode();
    DUMPVART(tOpenMode, int);
    const bool cOK = pFile->open(tOpenMode);
    DUMPVAR(pFile->errorString());
    TEXPECTIS(cOK);
    TEXPECTIS(pFile->openMode() == tOpenMode);
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
    DUMPVART(fileMode(), int);
    if (isOpen())
        if (file()->isReadable())
        {
            mBytes = file()->readAll();
            result = mBytes.length() == file()->size();
        }
    FNRETURN(bool(result));
    return result;
}

bool BaseFile::write()
{
    FNENTER();
    Q_ASSERT(!"Finished"); // TODO
    return false;
}









