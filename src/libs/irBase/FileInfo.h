#pragma once

#include <QFileInfo>
#include "Null.h"


#include <QDir>
#include <QMetaType>
#include <QString>

#include "FSText.h"
#include "FSTextList.h"
#include "Types.h"

class FileInfo : public QFileInfo, Null
{
public: // ctors
    FileInfo(const QFileInfo &other);
    FileInfo(const FSText &filePathName);
    FileInfo(const QDir &dir, const QString &fileName);

public: // const
    FSText dirFirst(const qsizetype k) const;
    FSText dirFirst(const qsizetype k, const char ch) const;
    FSText dirLast() const;
    QString toString();

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

