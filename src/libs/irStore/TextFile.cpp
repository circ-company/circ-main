#include "TextFile.h"

#include <QTimer>

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
