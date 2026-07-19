#include "Application.h"

#include <QFileSystemModel>
#include <QTimer>
#include <QVariant>
#include <QWidget>

#include <Log.h>
#include <NameFilters.h>

#include "irViewMainWindow.h"

Application::Application(int &argc, char **argv)
    : QQApplication(argc, argv)
    , mExeSupport("MainDesktop", this)
{
    LOG->initialize();
    FNENTER()
    setObjectName("Application:MainDesk");
}

void Application::run()
{
    FNENTER()
    PROGMSG("Running Application:" + mainWindow()->objectName());
    QQApplication::run();
    mainWindow()->show();
/*
    connect(this, &Application::running, mainWindow(), &MainWindow::run);
    connect(mainWindow(), &MainWindow::running, this, &Application::initialize);
    connect(this, &Application::initialized, mainWindow(), &MainWindow::initialize);
    connect(mainWindow(), &MainWindow::initialized, mainWindow(), &MainWindow::setup);
    connect(mainWindow(), &MainWindow::setuped, mainWindow(), &MainWindow::ready);
    connect(mainWindow(), &MainWindow::readied,  this, &Application::start);
*/
   FNEMIT(running);
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

    if (mMainDir.exists())
    {
        NameFilters mNF;
        mNF.setExtensions("JPG PNG");
        mainDir().setNameFilters(mNF.filterList());
        mainDir().setFilter(QDir::Files
                            | QDir::NoDotAndDotDot
                            | QDir::Readable);
        mFileList = mainDir().entryInfoList();
        emit initialized();
    }
    setup();
}

void Application::setup()
{
    FNENTER();

    FNRTNVOID();
}

void Application::start()
{
    FNENTER()

    QQApplication::start();
    if ( ! mFileList.isEmpty())
        QTimer::singleShot(50, this, &Application::processFile);
    emit started();
    FNEMIT(started);
    FNRTNVOID();
}

void Application::processFile()
{
    FNENTER()
    QQApplication::processFile();
    if (mFileList.isEmpty()) return;                                    /*/===\*/
    const FileInfo cFI = mFileList.takeFirst();
    QImage tImage(cFI.filePath());
    mainWindow()->setWindowTitle(cFI.toString(FileInfo::CompleteBaseName)
                                 + (tImage.isNull() ? " NULL" : ""));
    if (mFileList.isEmpty())
        QTimer::singleShot(5000, this, &QCoreApplication::quit);
    else
        QTimer::singleShot(5000, this, &Application::processFile);
    FNRTNVOID();
}
