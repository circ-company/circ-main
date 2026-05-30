#include "DirInfo.h"


DirInfo::DirInfo(const FSText &path) : QDir(path), Null(false) {;}
DirInfo::DirInfo(const QDir &other) : QDir(other), Null(false) {;}

bool DirInfo::isValidIndex(const Index ix) const
{
    return ix >= 0 && ix < Index(count());
}

FSTextList DirInfo::first(const Count k) const
{
    return FSTextList(mDirNames.first(k));
}

void DirInfo::clear()
{
    mDirNames.clear();
    nullify();
}

void DirInfo::set()
{
    QString tPath = QDir::fromNativeSeparators(QDir::path());
    mDirNames.set(tPath.split('/'));
}

void DirInfo::setTo(const FSText &fstx)
{
    QDir::setPath(fstx());
    fullify();
    set();
}

void DirInfo::setTo(const QDir &other)
{
    *this = other;
    fullify();
    set();
}
