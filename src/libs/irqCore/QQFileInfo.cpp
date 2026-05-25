#include "QQFileInfo.h"

#include <FSText.h>

QQFileInfo::QQFileInfo(const FSText &filePathName) : QFileInfo(filePathName), Null(false) {;}
QQFileInfo::QQFileInfo(const QDir &dir, const QString &fileName) : QFileInfo(dir, fileName), Null(false) {;}

FSText QQFileInfo::dirFirst(const qsizetype k) const
{
    return mDirNames.constFirst(k, char('/'));
}

FSText QQFileInfo::dirFirst(const qsizetype k, const char ch) const
{
    return mDirNames.constFirst(k, ch);
}

FSText QQFileInfo::dirLast() const
{
    return mDirNames.constLast();
}

