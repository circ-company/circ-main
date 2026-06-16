#pragma once

#include "FileInfo.h"
#include "List.h"

class FileInfoList : public ListT<FileInfo>
{
public:
    FileInfoList();
    FileInfoList(const QList<QFileInfo> &other);
    void set(const QList<QFileInfo> &other);
};
