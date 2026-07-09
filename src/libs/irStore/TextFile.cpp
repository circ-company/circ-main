#include "TextFile.h"

#include <QTimer>

#include <Log.h>

TextFile::TextFile()
{
    setObjectName("TextFile:Null");
}

TextFile::TextFile(const FileInfo &aFI,
                   const QIODevice::OpenMode aMode,
                   QObject *parent)
    : BaseFile(aFI, aMode | QIODevice::Text, parent)
{
    setObjectName("TextFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
    QTimer::singleShot(0, this, [this]()
    {
        emit infoSet(fileInfo(), exists());
        emit modeSet(fileInfo(), mode());
    });
}

TextFile::TextFile(const FSText &aFName,
                   const QIODeviceBase::OpenMode aMode,
                   QObject *parent)
    : BaseFile(aFName, aMode | QIODevice::Text, parent)

{
    setObjectName("TextFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
    QTimer::singleShot(0, this, [this]()
    {
        emit infoSet(fileInfo(), exists());
        emit modeSet(fileInfo(), mode());
    });
}

void TextFile::set(const QIODeviceBase::OpenMode aMode)
{
    mOpenMode = aMode | QIODevice::Text;
    emit modeSet(fileInfo(), mode());
}

bool TextFile::open(const QIODeviceBase::OpenMode aMode)
{
    FNENTER();
    FNARG(aMode);
    QIODeviceBase::OpenMode tOpenMode = aMode;
    if (QIODevice::NotOpen != tOpenMode)
        tOpenMode |= QIODevice::Text;
    return BaseFile::open(tOpenMode);
}

bool TextFile::read()
{
    FNENTER();
    bool result = BaseFile::read();
    if (result)
        mText.set(mBytes);
    FNRETURN(result);
    return result;
}
