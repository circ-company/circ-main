#include "Application.h"

#include <QTimer>
#include <QVariant>
#include <QWidget>

#include <Log.h>

#include "MainWindow.h"

Application::Application(int argc, char *argv[])
    : QQApplication(argc, argv)
{
    FNENTER()
    setObjectName("Application:MainDesk");
}

void Application::run()
{
    FNENTER()
    PROGMSG("Running Application" + mainWindow()->objectName());
    QQApplication::run();
    connect(this, &Application::running, mainWindow(), &MainWindow::run);
    connect(mainWindow(), &MainWindow::running, this, &Application::initialize);
    connect(this, &Application::initialized, mainWindow(), &MainWindow::initialize);
    connect(mainWindow(), &MainWindow::initialized, this, &Application::start);
    connect(this, &Application::started, mainWindow(), &MainWindow::setup);
    connect(mainWindow(), &MainWindow::setuped, mainWindow(), &MainWindow::ready);
    emit running();
}

void Application::initialize()
{
    FNENTER();
    QQApplication::initialize();
    if (argList().count() > 1)
        mMainDir.setPath(argAt(1));
    else
        mMainDir.setPath("../EFPin");
//    qDebug() << Q_FUNC_INFO << mMainDir.path() << mMainDir.exists();
    if (mMainDir.exists())
    {
        mpDirLoader = new DirLoader(this);
        dirLoader()->setNameFilters("JPG PNG");
        dirLoader()->setFilter(mDirFilters);
        dirLoader()->set(mMainDir);
        emit initialized();
    }
}

void Application::start()
{
    FNENTER()
    QQApplication::start();
    connect(dirLoader(), &DirLoader::file, this, &Application::processFile);
    dirLoader()->start();
    emit started();
}

void Application::processFile(const FileInfo fi)
{
    FNENTER()
    FNARG((QFileInfo(fi)));
  //  qDebug() << Q_FUNC_INFO << fi;
    QQApplication::processFile(fi);
    QImage tImage(fi.filePath());
    if (tImage.isNull()) return;                                        /*/===\*/
    mainWindow()->mainLabel()->set(tImage);
//    qDebug() << Q_FUNC_INFO << tImage;
    emit processedFile(fi, tImage);
}
