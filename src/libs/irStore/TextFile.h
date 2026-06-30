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

public: // const
    AText data() const;

public: // non-const
    virtual void set(const QIODevice::OpenMode aMode) override;
    virtual bool open(const QIODevice::OpenMode aMode=QIODevice::NotOpen) override;
    virtual bool read() override;


};

inline AText TextFile::data() const { return mText; }
