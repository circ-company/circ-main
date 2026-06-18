#include "File.h"

#include <FileInfo.h>
#include <Log.h>

File::File() : mOpenMode(QIODevice::NotOpen), mpFile(nullptr) {;}

File::File(const FileInfo &fi, const QIODeviceBase::OpenMode mode)
    : mFileInfo(fi)
    , mOpenMode(mode)
    , mpFile(nullptr)
{
    emit infoSet(mFileInfo, mFileInfo.exists());
}

File::File(const FSText &fstx, const QIODeviceBase::OpenMode mode)
    : mFileInfo(fstx)
    , mOpenMode(mode)
    , mpFile(nullptr)
{
    emit infoSet(mFileInfo, mFileInfo.exists());
}

Result File::open(const QIODeviceBase::OpenMode mode)
{
    FNENTER();
    FNARG(mode);
    Result result(CODECONTEXT());
    MUSTDO();

    FNLEAVER(result);
    return result;
}

void File::close()
{
    FNENTER();
    Result result(CODECONTEXT());
    Q_ASSERT(!"Finished"); // TODO

    FNLEAVE();
}

Result File::read()
{
    FNENTER();
    FNARG(mode);
    Result result(CODECONTEXT());
    Q_ASSERT(!"Finished"); // TODO
    FNLEAVER(result);
    return result;
}

Result File::write()
{
    FNENTER();
    FNARG(mode);
    Result result(CODECONTEXT());
    Q_ASSERT(!"Finished"); // TODO

    FNLEAVER(result);
    return result;
}








