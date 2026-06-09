#include "Application.h"

#include <QFileSystemModel>
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
    connect(mainWindow(), &MainWindow::initialized, mainWindow(), &MainWindow::setup);
    connect(mainWindow(), &MainWindow::setuped, mainWindow(), &MainWindow::ready);
    connect(mainWindow(), &MainWindow::readied,  this, &Application::start);
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
    TRACE2("MainDirPath=%1 Exists=%2", mMainDir.path(), mMainDir.exists());
    if (mMainDir.exists())
    {
        mpDirLoader = new DirLoader(this);
        dirLoader()->setNameFilters("JPG PNG");
        dirLoader()->setFilter(mDirFilters);
        dirLoader()->set(mMainDir);
        dirLoader()->initialize();
        QFileSystemModel * pModel = dirLoader()->model();
        connect(dirLoader(), &DirLoader::file, this, &Application::processFile);
        connect(pModel, &QFileSystemModel::rootPathChanged, this, &Application::rootDirChanged);
        connect(pModel, &QFileSystemModel::directoryLoaded, this, &Application::dirLoadFinished);
        emit initialized();
    }
}

void Application::start()
{
    FNENTER()
    QQApplication::start();
    dirLoader()->start();
    emit started();
}

void Application::processFile(const FileInfo fi)
{
    FNENTER()
    FNARG((QFileInfo(fi)));
    QQApplication::processFile(fi);
    QImage tImage(fi.filePath());
    TRACE2("FileName=%1 ImageSize=%2", fi.filePath(), tImage.size());
    if (tImage.isNull()) return;                                        /*/===\*/
    mainWindow()->mainLabel()->set(tImage);
    emit processedFile(fi, tImage);
}

void Application::rootDirChanged(const QString &path)
{
    FNENTER()
    FNARG((QFileInfo(path)));

}

void Application::dirLoadFinished(const QString &path)
{
    FNENTER()
    FNARG((QFileInfo(path)));

}
