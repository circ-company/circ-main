#pragma once

#include <QObject>

#include <QQueue>
class QTimer;

#include <Id.h>
#include <Types.h>
#include <Image.h>
#include <Url.h>

class BaseImageSource : public QObject
{
    Q_OBJECT
public: // types
    enum Option
    {
        $null       = 0,
        Loop        = 0x00000001,
        Randomize   = 0x00000002,
    };
    Q_DECLARE_FLAGS(Options, Option);

public: // ctors
//    explicit BaseImageSource(QObject *parent = nullptr);
    BaseImageSource(const Url aUrl, QObject *parent=nullptr);

public slots:
    void initialize(const Options aOptions);
    void run(const Milliseconds aSampleMsec);
    void stop();
    void dequeue();

protected slots:
    void enqueue(const Image &aImage);

signals:
    void ctord();
    void initialized();
    void running();
    void stopped();
    void enqueued(const Id aId, const Image &aImage);
    void dequeued(const Id aId, const Image &aImage);
    void taken(const Id aId, const Image &aImage);
    void loaded(const Count n);
    void looped(const Count n);
    void queueCount(const Count n);
    void empty();

public: // const
    bool isEmpty() const;
    Count count() const;
    Key key() const;

public: // non-const
    Image take();

protected:
    virtual void timerEvent(QTimerEvent *event);

private: // non-const
    virtual void handleEmpty();
    virtual void readSource() = 0;

protected:
    Options mOptions;
    Url mUrl;
    Milliseconds mSampleMsec=0;
    Qt::TimerId mTimerId=Qt::TimerId::Invalid;
    QQueue<Image> mReadyQueue;
    QQueue<Image> mUsedQueue;
};
