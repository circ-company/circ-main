#include "BaseImageSource.h"

#include <QTimer>

#include <Key.h>
#include <Id.h>
#include <Log.h>
/*
BaseImageSource::BaseImageSource(QObject *parent)
    : QObject{parent}
    , mpSampleTimer(new QTimer(this))
{
    setObjectName("BaseImageSource:null");
}
*/
BaseImageSource::BaseImageSource(const Url aUrl, QObject *parent)
    : QObject{parent}
    , mUrl(aUrl)
{
    setObjectName("BaseImageSource:" + mUrl.toString());
}

void BaseImageSource::initialize(const Options aOptions)
{
    FNENTER();
    FNARG(int(aOptions), int);

    mOptions = aOptions;

    emit initialized();
    FNEMIT("initialized");
    FNRTNVOID();
}

void BaseImageSource::run()
{
    FNENTER();

    readSource();
    if (mOptions & Randomize)
    {
        WANTDO("Randomize mReadyQueue");
    }

    emit running();
    FNEMIT("running");
    FNRTNVOID();
}

void BaseImageSource::dequeue()
{
    FNENTER();
    Image tImage = take();
    Id tId = tImage.id();
    Key tKey = tId.key();
    FNEMIT("dequeued");
    FNEMITARG("dequeued", tId.toString(), "QString");
    emit dequeued(tId, tImage);
    FNRTNVOID();
}

void BaseImageSource::checkSource()
{
    FNENTER();

    FNRTNVOID();
}

void BaseImageSource::sourceFinished()
{
    FNENTER();

    FNRTNVOID();
}

void BaseImageSource::enqueue(const Image &aImage)
{
//    FNENTER();
    const FileInfo cFI = aImage.fileInfo();
  //  FNARG(cFI.toString(), "QString");
    mReadyQueue.enqueue(aImage);
//    FNEMIT("enqueued");
  //  FNEMITARG("enqueued", cFI.toString(), "QString");
    //FNEMITARG("enqueued", aImage.toQImage().size(), "QSize");
  //  FNRTNVOID();
}

bool BaseImageSource::isEmpty() const
{
    return mReadyQueue.isEmpty();
}

Key BaseImageSource::key() const
{
    return Key(mUrl);
}

Image BaseImageSource::take()
{
    Image result;
    if (isEmpty())
    {
        if (mOptions & (Loop | Randomize))
        {
            WANTDO("randomize mUsedQueue");
        }
        else if (mOptions & Loop)
        {
            mReadyQueue = mUsedQueue;
            mUsedQueue.clear();
        }
    }
    // ...then...
    if ( ! isEmpty())
    {
        Image tImage = mReadyQueue.dequeue();
        if (mOptions & Loop)
            mUsedQueue.enqueue(tImage);
        result = tImage;
    }
    return result;
}



