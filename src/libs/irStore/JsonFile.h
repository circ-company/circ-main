#pragma once

#include "TextFile.h"

#include <QJsonDocument>
#include <QJsonParseError>

#include <Types.h>

class JsonFile : public TextFile
{
public:
    explicit JsonFile(QObject *parent = nullptr);
    JsonFile(const FileInfo &aFI,
             const QIODevice::OpenMode aMode=QIODevice::NotOpen,
             QObject *parent=nullptr);
    JsonFile(const FSText &aFName,
             const QIODevice::OpenMode aMode=QIODevice::NotOpen,
             QObject *parent=nullptr);

public: // const
    QJsonDocument document() const;
    QJsonParseError::ParseError error() const;
    QString errorString() const;
    SQWORD errorOffset() const;

public: // non-const
    void clear();
    virtual bool read() final;

private:
    QJsonDocument mDocument;
    QJsonParseError mParseError;
};

inline QJsonDocument JsonFile::document() const { return mDocument; }
inline QJsonParseError::ParseError JsonFile::error() const { return mParseError.error; }
inline QString JsonFile::errorString() const { return mParseError.errorString(); }

