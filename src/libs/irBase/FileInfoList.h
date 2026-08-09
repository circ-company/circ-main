#pragma once

#include "FileInfo.h"
#include <QList>

class FileInfoList : public QList<FileInfo>
{
public:
    FileInfoList();
    FileInfoList(const QList<QFileInfo> &other);
    void set(const QList<QFileInfo> &other);
};
