#include "FileImageSource.h"


FileImageSource::FileImageSource(const QDir aDir, QObject *parent)
    : BaseImageSource{Url(aDir), parent}
{
    setObjectName("FileImageSource:" + aDir.path());
}

void FileImageSource::readSource()
{
    QDir tDir = mFileInfo.dir();
    if (mFileInfo.suffix().isEmpty())
        tDir.setNameFilters(QStringList() << "*.jpg" << "*.png");
    else
        tDir.setNameFilters(QStringList() << "*." + mFileInfo.suffix());
    QFileInfoList tFIL = tDir.entryInfoList();
    for (Index ix = 0; ix < Index(tFIL.count()); ++ix)
    {
        Image tImage(FileInfo(tFIL.at(ix)));
        mReadyQueue.enqueue(tImage);
    }
}
