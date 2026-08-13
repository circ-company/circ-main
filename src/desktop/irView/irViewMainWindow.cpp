#include "irViewMainWindow.h"

#include <QMenu>
#include <QMenuBar>

#include <Action.h>
#include <ActionManager.h>
#include <Log.h>

irViewMainWindow::irViewMainWindow()
    : QMainWindow()
{
    setObjectName("irViewMainWindow");
}

irViewMainWindow::~irViewMainWindow()
{
}

void irViewMainWindow::run()
{
    FNENTER();

    FNEMIT(running);
    emit running();
    FNRTNVOID();
}

void irViewMainWindow::initialize()
{
    FNENTER();

    FNEMIT(initialized);
    emit initialized();
    FNRTNVOID();
}

void irViewMainWindow::setup()
{
    FNENTER();

    setupMenus();

    FNEMIT(setuped);
    emit setuped();
    FNRTNVOID();
}

void irViewMainWindow::start()
{
    FNENTER();


    FNEMIT(started);
    emit started();
    FNRTNVOID();
}

void irViewMainWindow::setupMenus()
{
    MASSERT(menuBar());
    QMenu * pFileMenu = new QMenu("File", this);
    MASSERT(pFileMenu);
    pFileMenu->addAction(ACTMGR->action("File/OpenFile")->qaction());
    pFileMenu->addAction(ACTMGR->action("File/OpenDir")->qaction());
    pFileMenu->addAction(ACTMGR->action("File/Close")->qaction());
    pFileMenu->addAction(ACTMGR->action("File/Exit")->qaction());
    menuBar()->addMenu(pFileMenu);
}


