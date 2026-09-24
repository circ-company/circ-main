#pragma once

#include <QObject>

#include <QQueue>

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
    BaseImageSource(const Url aUrl, QObject *parent=nullptr);

public slots:
    void initialize(const Options aOptions);
    void run();
    void dequeue();
    virtual void checkSource();
    virtual void sourceFinished();

protected slots:
    void enqueue(const Image &aImage);

signals:
    void ctord();
    void initialized();
    void running();
    void stopped();
    void enqueued(const Id aId, const Image &aImage);
    void dequeued(const Id aId, const Image &aImage);
    void loaded(const Count n);
    void looped(const Count n);
    void queueCount(const Count n);
    void empty();
    void checked();
    void checkFinished();

public: // const
    bool isEmpty() const;
    Count count() const;
    Key key() const;

public: // non-const
    Image take();

protected: // non-const
    virtual void readSource() = 0;

protected:
    Options mOptions;
    Url mUrl;
    QQueue<Image> mReadyQueue;
    QQueue<Image> mUsedQueue;
};

inline Count BaseImageSource::count() const { return mReadyQueue.count(); }
