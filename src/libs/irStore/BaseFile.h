#pragma once

#include <QObject>

#include <QByteArray>
#include <QIODevice>
#include <QString>
class QFile;

#include <AText.h>
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
    ~BaseFile();

public slots:
    void set(const FileInfo &aFI);
    void set(const FSText &aFileName);
    void close();

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
    QString error() const;
    QIODevice::OpenMode mode() const;
    bool exists() const;
    bool isOpen() const;
    bool isClosed() const;
    bool isEmpty() const;
    Count count() const;
    Index seekIndex() const;
    QByteArray bytes() const;
    AText text() const;

public: // non-const
    virtual void set(const QByteArray &bytes);
    virtual void set(const QIODevice::OpenMode aMode) = 0;
    virtual bool open(const QIODevice::OpenMode aMode=QIODevice::NotOpen);
    virtual bool read();
    bool write();
    void error(const QString aMsg);
    void clearError();

public: // pointers
    QFile * file();
    const BaseFile * it() const { return this; }
    BaseFile * it() { return this; }

protected:
    FileInfo mFileInfo;
    QIODevice::OpenMode mOpenMode=QIODevice::NotOpen;
    QFile * mpFile=nullptr;
    QString mErrorMessage;
    QByteArray mBytes;
    AText mText;
};

inline bool BaseFile::isNull() const { return mFileInfo.null(); }
inline FileInfo BaseFile::fileInfo() const { return isNull() ? FileInfo() : mFileInfo; }
inline QString BaseFile::error() const { return mErrorMessage; }
inline QIODevice::OpenMode BaseFile::mode() const { return isOpen() ? mpFile->openMode() : mOpenMode; }
inline bool BaseFile::exists() const { return fileInfo().exists(); }
inline bool BaseFile::isOpen() const { return mpFile ? mpFile->isOpen() : false; }
inline bool BaseFile::isClosed() const  { return ! isOpen(); }
inline bool BaseFile::isEmpty() const { return bytes().isEmpty(); }
inline Count BaseFile::count() const{ return isOpen() ? mpFile->size() : 0; }
inline Index BaseFile::seekIndex() const { return isOpen() ? mpFile->pos() : -1; }
inline QByteArray BaseFile::bytes() const { return mBytes; }
inline void BaseFile::error(const QString aMsg) { mErrorMessage = aMsg; }
inline void BaseFile::clearError() { mErrorMessage.clear(); }
inline void BaseFile::set(const QByteArray &bytes) { mBytes = bytes; }
inline QFile *BaseFile::file() { Q_CHECK_PTR(mpFile); return mpFile; }

