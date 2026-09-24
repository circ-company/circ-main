#include "FileImageSource.h"

#include <Log.h>

FileImageSource::FileImageSource(const QDir aDir, QObject *parent)
    : BaseImageSource{Url(aDir), parent}
    , mDir(aDir)
{
    setObjectName("FileImageSource:" + mDir.path());
    DUMPVAR(objectName());
}

void FileImageSource::readSource()
{
    FNENTER();
    DUMPVAR(mDir.path());
    mFIList = mDir.entryInfoList(Image::dirEntryFilters(), QDir::Files);
    DUMPVAR(mFIList.count());
    checkSource();
    FNRTNVOID();
}


void FileImageSource::checkSource()
{
    FNENTER();
    DUMPVAR(mFIList.count());
    DUMPVAR(UINT(count()));
    if (mFIList.isEmpty())
    {
        FNEMIT("checkFinished");
        emit checkFinished();
    }

    // then:
    if (count() > mLoQueuedCount)
    {
        ;
    }
    else if (count() < mHiQueuedCount)
    {
        const QFileInfo cFI = mFIList.takeFirst();
        Image tImage(cFI);
        DUMPVAR(cFI.filePath());
        DUMPVAR(tImage.toQImage().size());
        WEXPECTNOT(tImage.isNull());
        if ( ! tImage.isNull())
            enqueue(tImage);
    }
    else
    {
        ;
    }

    FNEMIT("checked");
    emit checked();
    FNEMIT("queueCount");
    FNEMITARG("queueCount", UINT(count()), "UINT");
    emit queueCount(count());
    FNRTNVOID();
}

void FileImageSource::sourceFinished()
{
    FNENTER()
    FNRTNVOID();
}
