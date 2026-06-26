#include "DataFile.h"

#include <QTimer>

DataFile::DataFile()
{
    setObjectName("DataFile:Null");
}

DataFile::DataFile(const FileInfo &aFI,
                   const QIODeviceBase::OpenMode mMode,
                   QObject *parent)
    : BaseFile(aFI, mMode & ~ QIODevice::Text, parent)
{
    setObjectName("DataFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
    QTimer::singleShot(0, this, [this]()
    {
        emit infoSet(fileInfo(), exists());
        emit modeSet(fileInfo(), mode());
    });
}

DataFile::DataFile(const FSText &aFName,
                   const QIODeviceBase::OpenMode mMode,
                   QObject *parent)
    : BaseFile(aFName, mMode & ~ QIODevice::Text, parent)
{
    setObjectName("DataFile:" + fileInfo().completeBaseName()
                  + "." + fileInfo().suffix());
    QTimer::singleShot(0, this, [this]()
    {
        emit infoSet(fileInfo(), exists());
        emit modeSet(fileInfo(), mode());
    });
}

