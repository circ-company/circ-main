#pragma once

#include <QObject>

#include <QByteArray>
#include <QIODevice>
class QFile;

#include <FileInfo.h>
#include <Types.h>
class FSText;

class BaseFile : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    BaseFile(QObject * parent=nullptr);
    BaseFile(const FileInfo &aFI,
             const QIODevice::OpenMode mMode=QIODevice::NotOpen,
             QObject * parent=nullptr);
    BaseFile(const FSText &aFName,
             const QIODevice::OpenMode mMode=QIODevice::NotOpen,
             QObject * parent=nullptr);

public slots:
    void set(const FileInfo &aFI);
    void set(const FSText &aFileName);
    bool open(const QIODevice::OpenMode aMode);
    void close();
    bool read();
    bool write();

signals:
    void infoSet(const FileInfo &fi, const bool exists);
    void modeSet(const FileInfo &fi, const QIODevice::OpenMode mode);
    void opened(const FileInfo &fi, const QIODevice::OpenMode mode);
    void closed(const FileInfo &fi);
    void dataRead(const FileInfo &fi, const Count byteCount, const Index seekIndex);
    void dataWritten(const FileInfo &fi, const Count byteCount, const Index seekIndex);

public: // const
    bool isNull() const;
    FileInfo fileInfo() const;
    QIODevice::OpenMode mode() const;
    bool exists() const;
    bool isOpen() const;
    bool isClosed() const;
    bool isEmpty() const;
    Count count() const;
    Index seekIndex() const;
    QByteArray bytes() const;

public: // non-const
    void set(const QByteArray &bytes);
    void set(const QIODevice::OpenMode mode);

public: // pointers
    QFile * file();
    const BaseFile * it() const { return this; }
    BaseFile * it() { return this; }

private:
    FileInfo mFileInfo;
    QIODevice::OpenMode mOpenMode=QIODevice::NotOpen;
    QFile * mpFile=nullptr;
    QByteArray mBytes;
};

inline bool BaseFile::isNull() const { return mFileInfo.null(); }
inline FileInfo BaseFile::fileInfo() const { return isNull() ? FileInfo() : mFileInfo; }
inline QIODevice::OpenMode BaseFile::mode() const { return isOpen() ? mpFile->openMode() : mOpenMode; }
inline bool BaseFile::exists() const { return fileInfo().exists(); }
inline bool BaseFile::isOpen() const { return mpFile ? mpFile->isOpen() : false; }
inline bool BaseFile::isClosed() const  { return ! isOpen(); }
inline bool BaseFile::isEmpty() const { return bytes().isEmpty(); }
inline Count BaseFile::count() const{ return isOpen() ? mpFile->size() : 0; }
inline Index BaseFile::seekIndex() const { return isOpen() ? mpFile->pos() : -1; }
inline QByteArray BaseFile::bytes() const { return mBytes; }
inline void BaseFile::set(const QByteArray &bytes) { mBytes = bytes; }
inline void BaseFile::set(const QIODeviceBase::OpenMode mode) { mOpenMode = mode; }
inline QFile *BaseFile::file() { Q_CHECK_PTR(mpFile); return mpFile; }

