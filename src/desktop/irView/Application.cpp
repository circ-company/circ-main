#include "Application.h"

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

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
    , mpMainWindow(new irViewMainWindow)
{
    LOG->initialize();
    setObjectName("Application:irView");
}

void Application::run()
{
    FNENTER();
    PROGMSG("Running Application:" + mainWindow()->objectName());
    mainWindow()->show();
    connect(this, &Application::running, mainWindow(), &irViewMainWindow::run);
    connect(mainWindow(), &irViewMainWindow::running, this, &Application::initialize);
    connect(this, &Application::initialized, mainWindow(), &irViewMainWindow::initialize);
    connect(mainWindow(), &irViewMainWindow::initialized, this, &Application::setup);
    connect(this, &Application::setuped, mainWindow(), &irViewMainWindow::setup);
    connect(mainWindow(), &irViewMainWindow::setuped, this, &Application::start);
    connect(this, &Application::started, mainWindow(), &irViewMainWindow::start);
    FNEMIT(running);
    emit running();
    FNRTNVOID();
}

void Application::initialize()
{
    FNENTER();

    initActions();

    FNEMIT(initialized);
    emit initialized();
    FNRTNVOID();
}

void Application::setup()
{
    FNENTER();


    FNEMIT(setuped);
    emit setuped();
    FNRTNVOID();
}

void Application::start()
{
    FNENTER();

    FNEMIT(started);
    emit started();
    FNRTNVOID();
}

void Application::initActions()
{
    Action * pFileOpen = ACTMGR->add("File/&OpenFile");
    Action * pFileDir = ACTMGR->add("File/Open&Dir");
    Action * pFileClose = ACTMGR->add("File/&Close");
    Action * pFileExit = ACTMGR->add("File/E&xit");
    MASSERT(pFileOpen); MASSERT(pFileDir);
    MASSERT(pFileClose); MASSERT(pFileExit);
    pFileOpen->qaction()->setShortcut(QKeySequence::Open);
    pFileDir->qaction()->setShortcut(QKeySequence("Alt+D"));
    pFileClose->qaction()->setShortcut(QKeySequence("Alt+D"));
    pFileExit->qaction()->setShortcut(QKeySequence("Alt+D"));
}

