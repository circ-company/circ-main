
#include <QtDebug>
#include <QTimer>

#include <VersionInfo.h>

#include "MainConsoleApplication.h"

int main(int argc, char *argv[])
{
    qInfo() << Q_FUNC_INFO << argc;

    MainConsoleApplication a(argc, argv);
    QTimer::singleShot(100, &a, &MainConsoleApplication::initialize);
    qInfo() << Q_FUNC_INFO << "exec'ing";
    return a.exec();
}
