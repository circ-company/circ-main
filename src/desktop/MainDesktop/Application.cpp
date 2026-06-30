#include "Application.h"

#include <QFileSystemModel>
#include <QTimer>
#include <QVariant>
#include <QWidget>

#include <Log.h>
#include <NameFilters.h>
#include <cvODCatalog.h>

#include "MainWindow.h"

Application::Application(int &argc, char **argv)
    : QQApplication(argc, argv)
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
    connect(this, &Application::running, mainWindow(), &MainWindow::run);
    connect(mainWindow(), &MainWindow::running, this, &Application::initialize);
    connect(this, &Application::initialized, mainWindow(), &MainWindow::initialize);
    connect(mainWindow(), &MainWindow::initialized, mainWindow(), &MainWindow::setup);
    connect(mainWindow(), &MainWindow::setuped, mainWindow(), &MainWindow::ready);
    connect(mainWindow(), &MainWindow::readied,  this, &Application::start);
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

    const Url cCatUrl(QUrl::fromLocalFile("../Detectors/Detectors.xml").toString());
    mpCatalog = new cvODCatalog(cCatUrl, this);
    NEWOBJ(mpCatalog, cvODCatalog, this);

    TRACE2("MainDirPath=%1 Exists=%2", mMainDir.path(), mMainDir.exists());
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
    catalog()->read();
    catalog()->parse();
}

void Application::start()
{
    FNENTER()

    QQApplication::start();
    if ( ! mFileList.isEmpty())
        QTimer::singleShot(50, this, &Application::processFile);
    emit started();
}

void Application::processFile()
{
    FNENTER()
    QQApplication::processFile();
    if (mFileList.isEmpty()) return;                                    /*/===\*/
    const FileInfo cFI = mFileList.takeFirst();
    QImage tImage(cFI.filePath());
    TRACE2("FileName=%1 ImageSize=%2", cFI.filePath(), tImage.size());
    mainWindow()->setWindowTitle(cFI.toString(FileInfo::CompleteBaseName)
                                 + (tImage.isNull() ? " NULL" : ""));
    if ( ! tImage.isNull())
    {
        mainWindow()->mainLabel()->set(mainWindow()->mainLabel()->size(), tImage);
        emit processedFile(cFI, tImage);
    }
    if (mFileList.isEmpty())
        QTimer::singleShot(5000, this, &QCoreApplication::quit);
    else
        QTimer::singleShot(5000, this, &Application::processFile);
}
