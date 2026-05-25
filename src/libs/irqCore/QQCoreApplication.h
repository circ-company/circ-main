#pragma once

#include <QCoreApplication>
#include <QObject>
#include <QTextStream>
class QTimer;

#include <Types.h>

#include <VersionInfo.h>


class QQCoreApplication : public QCoreApplication
{
    Q_OBJECT
protected: // ctors
    QQCoreApplication(int &argc, char **argv);
public:
    ~QQCoreApplication();

public slots:
    virtual void initialize();
    virtual void run() = 0;

protected slots:
    void initializeTimers();
    void killQuitTimer();
    virtual void runTimer();
    virtual void quitTimer();

signals:
    void initialized();
    void timerStarted(const Milliseconds ms, QTimer * pt);
    void timerKilled(const Milliseconds ms, QTimer * pt);

public: // const
    VersionInfo versionInfo() const;

public: // non-const
    void set(const VersionInfo &vi);
    void set(const Milliseconds runMSec, const Milliseconds quitMSec);

public: // pointers
    QTextStream & cout();

protected slots:

private:
    QTextStream mCout;
    VersionInfo mVersion;
    Milliseconds mRunTimerMSec=200;
    Milliseconds mQuitTimerMSec=60000;
//    QTimer * mpRunTimer=nullptr;
    QTimer * mpQuitTimer=nullptr;
};

inline VersionInfo QQCoreApplication::versionInfo() const { return mVersion; }
inline QTextStream &QQCoreApplication::cout() { return mCout; }


