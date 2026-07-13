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

QFileInfo FileInfo::toQFileInfo() const
{
    return *(QFileInfo *)&(it());
}

QVariant FileInfo::toVariant() const
{
    QVariant result;
    if (full()) result.setValue<QFileInfo>(toQFileInfo());
    return result;
}

QString FileInfo::toString(const StringOptions aOptions) const
{
    QString result;
    if (null())
    {
        result = "{NULL}";
        return result;                                          /*/=====\*/
    }
    if (aOptions.testFlag(CompleteBaseName))
        result.append(" " + completeBaseName() + " ");
    if (aOptions.testFlag(NullFull))
        result.append(" " + QString(full()
                                        ? "Full"
                                        : (aOptions.testFlag(Negatives)
                                               ? "NULL"
                                               : "")) + " ");
    if (aOptions.testFlag(Readable))
        result.append(" " + QString(isReadable()
                                 ? "Readable"
                                 : (aOptions.testFlag(Negatives)
                                        ? "NOT Readable"
                                        : "")) + " ");
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

