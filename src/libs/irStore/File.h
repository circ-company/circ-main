#pragma once

#include <QObject>

#include <QByteArray>
#include <QIODevice>
class QFile;

#include <Result.h>
#include <Types.h>
class FileInfo;
class FSText;

class File : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    File();
    File(const FileInfo &fi, const QIODevice::OpenMode mMode=QIODevice::NotOpen);
    File(const FSText &fstx, const QIODevice::OpenMode mMode=QIODevice::NotOpen);

public slots:
    void set(const FileInfo &fi);
    void set(const FSText &fstx);
    Result open(const QIODevice::OpenMode mode);
    void close();
    Result read();
    Result write();

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
    const File * it() const { return this; }
    File * it() { return this; }

private:
    FileInfo mFileInfo;
    QIODevice::OpenMode mOpenMode=QIODevice::NotOpen;
    QFile * mpFile=nullptr;
    QByteArray mBytes;
};

inline bool File::isNull() const { return mFileInfo.null(); }
inline FileInfo File::fileInfo() const { return isNull() ? FileInfo() : mFileInfo; }
inline QIODevice::OpenMode File::mode() const { return isOpen() ? mpFile->openMode() : mOpenMode; }
inline bool File::isOpen() const { return mpFile ? mpFile->isOpen() : false; }
inline bool File::isClosed() const  { return ! isOpen(); }
inline bool File::isEmpty() const { return bytes().isEmpty(); }
inline Count File::count() const{ return isOpen() ? mpFile->size() : 0; }
inline Index File::seekIndex() const { return isOpen() ? mpFile->pos() : -1; }
inline QByteArray File::bytes() const { return mBytes; }
inline void File::set(const QByteArray &bytes) { mBytes = bytes; }
inline void File::set(const QIODeviceBase::OpenMode mode) { mOpenMode = mode; }
inline QFile *File::file() { Q_CHECK_PTR(mpFile); return mpFile; }

