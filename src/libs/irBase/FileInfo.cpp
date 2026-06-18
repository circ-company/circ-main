#include "FileInfo.h"

FileInfo::FileInfo(const QFileInfo &other)
    : QFileInfo(other), Null(false) { setDirs(); }
FileInfo::FileInfo(const FSText &filePathName)
    : QFileInfo(filePathName), Null(false) { setDirs(); }
FileInfo::FileInfo(const QDir &dir, const QString &fileName)
    : QFileInfo(dir, fileName), Null(false) { setDirs(); }

bool FileInfo::exists() const
{
    return full() ? QFileInfo::exists() : false;
}

FSText FileInfo::dirFirst(const qsizetype k) const
{
    return dirFirst(k, '/');
}

FSText FileInfo::dirFirst(const qsizetype k, const char ch) const
{
    FSTextList tOldList(mDirNames), tNewList;
    while (tNewList.count() < k)
        tNewList.append(tOldList.takeFirst());
    return tNewList.join(ch);
}

FSText FileInfo::dirLast() const
{
    return mDirNames.constLast();
}

QString FileInfo::toString()
{
    QString result;
    // TODO
    return result;
}

void FileInfo::clear()
{
    QFileInfo::setFile("");
    Null::nullify();
}

void FileInfo::setDirs()
{
    FSText tDirNameText = dir().path();
    mDirNames = tDirNameText.split('/');
}

