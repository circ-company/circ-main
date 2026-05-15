#include "QQCoreApplication.h"

#include <QtDebug>
#include <QTimer>

QQCoreApplication::QQCoreApplication(int &argc, char **argv)
    : QCoreApplication(argc, argv)
    , mCout(stdout)
{
    qInfo() << Q_FUNC_INFO << argc << arguments().join(' ');
    setObjectName("QQCoreApplication");
}

QQCoreApplication::~QQCoreApplication()
{
    qInfo() << Q_FUNC_INFO;
    if (mpQuitTimer)
    {
        mpQuitTimer->stop();
        mpQuitTimer->deleteLater();
        mpQuitTimer = nullptr;
    }
}

void QQCoreApplication::initialize()
{
    qInfo() << Q_FUNC_INFO;

    initializeTimers();
}

void QQCoreApplication::initializeTimers()
{
    qInfo() << Q_FUNC_INFO << mRunTimerMSec << " " << mQuitTimerMSec;
    mpQuitTimer = new QTimer(this);
    Q_CHECK_PTR(mpQuitTimer);
    mpQuitTimer->setObjectName("QuitTimer");
    QTimer::singleShot(mRunTimerMSec, this, &QQCoreApplication::runTimer);
    emit timerStarted(mRunTimerMSec, nullptr);
    mpQuitTimer->singleShot(mQuitTimerMSec, this, &QQCoreApplication::quitTimer);
    emit timerStarted(mQuitTimerMSec, mpQuitTimer);
}

void QQCoreApplication::killQuitTimer()
{
    qInfo() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpQuitTimer);
    mpQuitTimer->stop();
    emit timerKilled(mpQuitTimer->interval(), mpQuitTimer);
    mpQuitTimer->deleteLater();
    mpQuitTimer = nullptr;
}

void QQCoreApplication::set(const Milliseconds runMSec, const Milliseconds quitMSec)
{
    qInfo() << Q_FUNC_INFO;
    mRunTimerMSec = runMSec, mQuitTimerMSec = quitMSec;
}

void QQCoreApplication::runTimer()
{
    qInfo() << Q_FUNC_INFO;
    run();
}

void QQCoreApplication::quitTimer()
{
    qInfo() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpQuitTimer);
    mpQuitTimer->deleteLater();
    mpQuitTimer = nullptr;
    quit();
}

void QQCoreApplication::set(const VersionInfo &vi)
{
    mVersion = vi;
    setApplicationVersion(mVersion.toString());
    setApplicationName(mVersion.appname());
    setOrganizationName(mVersion.orgname());
}


