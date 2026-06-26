#pragma once

#include "BaseFile.h"

class DataFile : public BaseFile
{
    Q_OBJECT
public:
    DataFile();
    DataFile(const FileInfo &aFI,
             const QIODevice::OpenMode mMode=QIODevice::NotOpen,
             QObject *parent=nullptr);
    DataFile(const FSText &aFName,
             const QIODevice::OpenMode mMode=QIODevice::NotOpen,
             QObject *parent=nullptr);
};
