#include "MainConsoleApplication.h"

#include <QtDebug>
#include <QDateTime>
#include <QStringList>
#include <QTextStream>
#include <QTimer>


#include <version.h>

MainConsoleApplication::MainConsoleApplication(int &argc, char **argv)
    : QQCoreApplication(argc, argv)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("MainConsoleApplication");
    connect(this, &QQCoreApplication::initialized,
            this, &MainConsoleApplication::intro);
    connect(this, &MainConsoleApplication::introed,
            this, &MainConsoleApplication::versions);
    connect(this, &MainConsoleApplication::versioned,
            this, &QCoreApplication::quit);
    connect(this, &QQCoreApplication::timerStarted,
            this, &MainConsoleApplication::timerStart);
    connect(this, &QQCoreApplication::timerKilled,
            this, &MainConsoleApplication::timerKill);
}

void MainConsoleApplication::run()
{
    qInfo() << Q_FUNC_INFO;
    cout() << "Running.";
    killQuitTimer();
    emit running();
}

void MainConsoleApplication::initialize()
{
    qInfo() << Q_FUNC_INFO;
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE, VER_BRANCH, VER_BUILD,
                   VER_BRANCHNAME, "MainConsole", VER_ORGNAME, VER_COMMENT);
    vi.copyright(VER_COPYRIGHT);
    vi.legal(VER_LEGAL);
    set(vi);
    QQCoreApplication::initialize();
    emit initialized();
}

void MainConsoleApplication::intro()
{
    qInfo() << Q_FUNC_INFO;
    QStringList tArgList = arguments();
    const QString cExe = tArgList.takeFirst();
    const QString cArgs = tArgList.join(' ');
    cout() << "===Welcome to " << applicationName() << " by " << organizationName() << Qt::endl;
    cout() << "---from " << cExe << " with " << (cArgs.isEmpty() ? "{none}" : cArgs) << Qt::endl;
    cout() << "---at " << QDateTime::currentDateTime().toString()  << Qt::endl;
    emit introed();
}

void MainConsoleApplication::versions()
{
    qInfo() << Q_FUNC_INFO;
    cout() << "===Versions:" << Qt::endl;
    cout() << "---Application:  v" << applicationVersion() << Qt::endl;
    cout() << "   " << versionInfo().copyright() << Qt::endl;
    cout() << "   " << versionInfo().legal() << Qt::endl;
    cout() << "---Qt Lib Build: v" << qVersion() << Qt::endl;
    cout() << "---Qt App Build: v" << QT_VERSION_STR << Qt::endl;

    emit versioned();
}

void MainConsoleApplication::timerStart(const Milliseconds ms, QTimer *pt)
{
    qInfo() << Q_FUNC_INFO << ms << pt;
    cout() << ">>>Timer Start: " << ms << "msec "
           << (pt ? pt->objectName() : "{null}") << Qt::endl;
}

void MainConsoleApplication::timerKill(const Milliseconds ms, QTimer *pt)
{
    qInfo() << Q_FUNC_INFO << ms << pt;
    cout() << ">>>Timer Killed: " << ms << "msec "
           << (pt ? pt->objectName() : "{null}") << Qt::endl;
}
