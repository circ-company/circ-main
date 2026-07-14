#pragma once

#include "BaseFile.h"

class TextFile : public BaseFile
{
    Q_OBJECT
public:
    TextFile(QObject * parent=nullptr);
    TextFile(const FileInfo &aFI,
             const QIODevice::OpenMode aMode=QIODevice::NotOpen,
             QObject *parent=nullptr);
    TextFile(const FSText &aFName,
             const QIODevice::OpenMode aMode=QIODevice::NotOpen,
             QObject *parent=nullptr);

public: // const

public: // non-const
    virtual void set(const QIODevice::OpenMode aMode) override;
    virtual bool open(const QIODevice::OpenMode aMode=QIODevice::NotOpen) override;
    virtual bool read() override;
    virtual AText data();

private:
    AText mText;
};



