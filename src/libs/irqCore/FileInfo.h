#pragma once

#include <QFileInfo>
#include <QMetaType>

#include <QDir>
#include <QString>

class FileInfo : public QFileInfo
{
public:
    FileInfo(const QDir &dir, const QString &fileName);

public: // QMetaType
    FileInfo() = default;
    ~FileInfo() = default;
    FileInfo(const FileInfo &) = default;
    FileInfo &operator=(const FileInfo &) = default;
};

Q_DECLARE_METATYPE(FileInfo);


