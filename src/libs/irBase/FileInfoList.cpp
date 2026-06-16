#include "FileInfoList.h"


FileInfoList::FileInfoList() {;}
FileInfoList::FileInfoList(const QList<QFileInfo> &other) { set(other); }

void FileInfoList::set(const QList<QFileInfo> &other)
{
    clear();
    foreach (const QFileInfo cQFI, other)
        append(FileInfo(cQFI));
}

