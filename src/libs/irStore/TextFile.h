#pragma once

#include "BaseFile.h"

class TextFile : public BaseFile
{
    Q_OBJECT
public:
    TextFile();
    TextFile(const FileInfo &aFI,
             const QIODevice::OpenMode aMode=QIODevice::NotOpen,
             QObject *parent=nullptr);
    TextFile(const FSText &aFName,
             const QIODevice::OpenMode aMode=QIODevice::NotOpen,
             QObject *parent=nullptr);
};
