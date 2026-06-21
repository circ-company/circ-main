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

void File::set(const FileInfo &fi)
{
    mFileInfo = fi;
    emit infoSet(mFileInfo, mFileInfo.exists());
}

void File::set(const FSText &fstx)
{
    set(FileInfo(fstx));
}

Result File::open(const QIODeviceBase::OpenMode mode)
{
    FNENTER();
    FNARG(mode);
    Result result(CODECONTEXT());
    MUSTDO();
    StatusItem tStartStatus("CIRCCOcom/circ-main/irStore/File/open", CODECONTEXT());
    tStartStatus.add(int(mode));
    tStartStatus.add(mFileInfo.toVariant());
    result.add(tStartStatus);

    StatusItem tNewStatus("CIRCCOcom/circ-main/irStore/File/open/new", CODECONTEXT());


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
    Result result(CODECONTEXT());
    Q_ASSERT(!"Finished"); // TODO
    FNLEAVER(result);
    return result;
}

Result File::write()
{
    FNENTER();
    Result result(CODECONTEXT());
    Q_ASSERT(!"Finished"); // TODO

    FNLEAVER(result);
    return result;
}








