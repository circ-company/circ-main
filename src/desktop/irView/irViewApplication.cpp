#include "irViewApplication.h"

#include <QAction>
#include <QFileSystemModel>
#include <QKeySequence>
#include <QTimer>
#include <QVariant>
#include <QWidget>

#include <Action.h>
#include <ActionManager.h>
#include <Log.h>
#include <NameFilters.h>

#include "irViewMainWindow.h"

irViewApplication::irViewApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , mpMainWindow(new irViewMainWindow(this))
{
    LOG->initialize();
    setObjectName("Application:irView");
    QDir tCurrentDir = FileInfo(arguments().first()).dir();
    if (tCurrentDir.exists("../Input")) tCurrentDir.cd("../Input");
    mCurrentDir.set(tCurrentDir);
}

void irViewApplication::run()
{
    FNENTER();
    PROGMSG("Running Application:" + mainWindow()->objectName());
    mainWindow()->show();
    connect(this, &irViewApplication::running, mainWindow(), &irViewMainWindow::run);
    connect(mainWindow(), &irViewMainWindow::running, this, &irViewApplication::initialize);
    connect(this, &irViewApplication::initialized, mainWindow(), &irViewMainWindow::initialize);
    connect(mainWindow(), &irViewMainWindow::initialized, this, &irViewApplication::setup);
    connect(this, &irViewApplication::setuped, mainWindow(), &irViewMainWindow::setup);
    connect(mainWindow(), &irViewMainWindow::setuped, this, &irViewApplication::start);
    connect(this, &irViewApplication::started, mainWindow(), &irViewMainWindow::start);
    FNEMIT(running);
    emit running();
    FNRTNVOID();
}

void irViewApplication::initialize()
{
    FNENTER();

    initActions();
    DUMPQSL(actmgr().toDebugStrings());

    FNEMIT(initialized);
    emit initialized();
    FNRTNVOID();
}

void irViewApplication::setup()
{
    FNENTER();

    connectActions();

    FNEMIT(setuped);
    emit setuped();
    FNRTNVOID();
}

void irViewApplication::start()
{
    FNENTER();

    FNEMIT(started);
    emit started();
    FNRTNVOID();
}

void irViewApplication::fileOpen()
{
    FNENTER();
    FileInfo tFI = mainWindow()->doFileOpenDialog();
    DUMPVAR(tFI);

    FNEMITARG("fileOpened", tFI, "FileInfo");
    emit fileOpened(tFI);
    FNRTNVOID();

}

void irViewApplication::dirOpen()
{
    FNENTER();
    FileInfo tFI;

    FNEMITARG("dirOpened", tFI, "FileInfo");
    emit dirOpened(tFI);
    FNRTNVOID();

}

void irViewApplication::fileClose()
{
    FNENTER();
    FileInfo tFI;

    FNEMITARG("fileClosed", tFI, "FileInfo");
    emit fileClosed(tFI);
    FNRTNVOID();
}

void irViewApplication::fileExit()
{
    FNENTER();
    qApp->quit();
    FNRTNVOID();
}

void irViewApplication::initActions()
{
    FNENTER();
    Action * pFileOpen = actmgr().add("File/OpenFile");
    Action * pFileDir = actmgr().add("File/OpenDir");
    Action * pFileClose = actmgr().add("File/Close");
    Action * pFileExit = actmgr().add("File/Exit");
    CKPOINTER(pFileOpen); CKPOINTER(pFileDir);
    CKPOINTER(pFileClose); CKPOINTER(pFileExit);
    pFileOpen->qaction()->setShortcut(QKeySequence::Open);
    pFileDir->qaction()->setShortcut(QKeySequence("Ctrl+D"));
    pFileClose->qaction()->setShortcut(QKeySequence::Close);
    pFileExit->qaction()->setShortcut(QKeySequence::Quit);
    FNRTNVOID();
}

void irViewApplication::connectActions()
{
    FNENTER();
    connect(actmgr().action("File/OpenFile")->qaction(),
            &QAction::triggered, this, &irViewApplication::fileOpen);
    connect(actmgr().action("File/OpenDir")->qaction(),
            &QAction::triggered, this, &irViewApplication::dirOpen);
    connect(actmgr().action("File/Close")->qaction(),
            &QAction::triggered, this, &irViewApplication::fileClose);
    connect(actmgr().action("File/Exit")->qaction(),
            &QAction::triggered, this, &irViewApplication::fileExit);
    FNRTNVOID();
}

