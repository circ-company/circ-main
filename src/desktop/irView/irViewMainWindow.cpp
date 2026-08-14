#include "irViewMainWindow.h"

#include <QMenu>
#include <QMenuBar>

#include <Action.h>
#include <ActionManager.h>
#include <Log.h>

#include "irViewApplication.h"

irViewMainWindow::irViewMainWindow(irViewApplication * pApp)
    : QMainWindow()
    , mpApplication(pApp)
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

FileInfo irViewMainWindow::doFileOpenDialog()
{
    FNENTER();
    if ( ! mpFileDialog)
    {
        mpFileDialog = new QFileDialog(this, tr("Open Image File", "UI"));
        NEWOBJ(mpFileDialog, "QFileDialog", this);
        mpFileDialog->setDirectory(app()->currentDir());
        mpFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
        mpFileDialog->setFileMode(QFileDialog::ExistingFiles);
        mpFileDialog->setViewMode(QFileDialog::List);
        mpFileDialog->setDefaultSuffix("jpg");
        mpFileDialog->setOption(QFileDialog::ReadOnly);
    }
    mpFileDialog->open();
    FNRTNVOID();
    return FileInfo(); // TODO
}

void irViewMainWindow::setupMenus()
{
    FNENTER();
    DUMPQSL(app()->actmgr().toDebugStrings());
    MASSERT(menuBar());
    QMenu * pFileMenu = new QMenu("File", this);
    MASSERT(pFileMenu);
    pFileMenu->addAction(app()->actmgr().action("File/OpenFile")->qaction());
    pFileMenu->addAction(app()->actmgr().action("File/OpenDir")->qaction());
    pFileMenu->addAction(app()->actmgr().action("File/Close")->qaction());
    pFileMenu->addSeparator();
    pFileMenu->addAction(app()->actmgr().action("File/Exit")->qaction());
    menuBar()->addMenu(pFileMenu);
    FNRTNVOID();
}


