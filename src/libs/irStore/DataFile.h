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

public: // const
    QByteArray data() const;

public: // non-const
    virtual void set(const QIODevice::OpenMode aMode) override;
    virtual bool open(const QIODevice::OpenMode aMode=QIODevice::NotOpen) override;
    virtual bool read() override;

};

inline QByteArray DataFile::data() const { return mBytes; }
