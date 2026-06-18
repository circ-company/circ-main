#pragma once

#include <QFileInfo>
#include "Null.h"


#include <QDir>
#include <QMetaType>
#include <QString>

#include "FSText.h"
#include "FSTextList.h"

class FileInfo : public QFileInfo, public Null
{
public: // types
    typedef QList<FileInfo> List;

public: // ctors
    FileInfo(const QFileInfo &other);
    FileInfo(const FSText &filePathName);
    FileInfo(const QDir &dir, const QString &fileName);

public: // const
    bool exists() const;
    FSText dirFirst(const qsizetype k) const;
    FSText dirFirst(const qsizetype k, const char ch) const;
    FSText dirLast() const;
    QString toString();

public: // non-const
    void clear();

private: // non-const
    void setDirs();

private:
    FSTextList mDirNames;

public: // QMetaType
    FileInfo() = default;
    ~FileInfo() = default;
    FileInfo(const FileInfo &) = default;
    FileInfo &operator=(const FileInfo &) = default;
};

Q_DECLARE_METATYPE(FileInfo);

