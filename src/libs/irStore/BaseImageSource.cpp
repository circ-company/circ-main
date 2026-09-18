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

void BaseImageSource::run(const Milliseconds aSampleMsec)
{
    FNENTER();
    FNARG(aSampleMsec, Milliseconds);
    mSampleMsec = aSampleMsec;
    if (mSampleMsec)
    {
        mTimerId = Qt::TimerId(startTimer(mSampleMsec));
        emit running();
        FNEMIT("running");
    }
    FNRTNVOID();
}

void BaseImageSource::stop()
{
    FNENTER();
    if (mSampleMsec)
    {
        killTimer(mTimerId);
        mTimerId = Qt::TimerId::Invalid;
        mSampleMsec = 0;
        emit stopped();
        FNEMIT("stopped");
    }
    else
    {
        WARNING("Already stopped");
    }
    FNRTNVOID();
}

void BaseImageSource::dequeue()
{
    FNENTER();
    if (isEmpty())
    {
        handleEmpty();
    }
    // ...then...
    if ( ! isEmpty())
    {
        Image tImage = mReadyQueue.dequeue();
        if (mOptions & Loop)
            mUsedQueue.enqueue(tImage);
        Id tId = tImage.id();
        Key tKey = tId.key();
        FNEMIT("dequeued");
        FNEMITARG("dequeued", tId.toString(), "QString");
        emit dequeued(tId, tImage);
    }
    FNRTNVOID();
}

void BaseImageSource::enqueue(const Image &aImage)
{
    FNENTER();
    const Id cId = aImage.id();
    FNARG(cId.toString(), "QString");
    mReadyQueue.enqueue(aImage);
    FNEMIT("enqueued");
    FNEMITARG("enqueued", cId.toString(), "QString");
    FNEMITARG("enqueued", aImage.toQImage().size(), "QSize");
    FNRTNVOID();
}

bool BaseImageSource::isEmpty() const
{
    return mReadyQueue.isEmpty();
}

Key BaseImageSource::key() const
{
    return Key(mUrl);
}

void BaseImageSource::timerEvent(QTimerEvent *event)
{
    if (event->id() == mTimerId)
    {
        dequeue();
    }
}

void BaseImageSource::handleEmpty()
{
    if (mOptions & (Loop | Randomize))
    {
        WANTDO("randomize");
    }
    else if (mOptions & Loop)
    {
        mReadyQueue = mUsedQueue;
        mUsedQueue.clear();
    }
}

