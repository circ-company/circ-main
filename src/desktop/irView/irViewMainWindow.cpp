#include "irViewMainWindow.h"

#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>

#include <Action.h>
#include <ActionManager.h>
#include <Log.h>

#include "irViewApplication.h"

irViewMainWindow::irViewMainWindow(irViewApplication * pApp)
    : QMainWindow()
    , mpApplication(pApp)
    , mLabelMap(this)
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
    mpMenuBar = new QMenuBar(this);
    NEWOBJ(mpMenuBar, "QMenuBar", this);
    setMenuBar(mpMenuBar);
    mpMenuBar->show();

    setupMenus();

    mpMainLabel = new Label(this);
    NEWOBJ(mpMainLabel, "Label", this);
    setCentralWidget(mpMainLabel);
    setMenuBar(mpMenuBar);

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

void irViewMainWindow::doFileOpenDialog()
{
    FNENTER();
    static QDir smCurrentDir = app()->currentDir();
    QStringList tFileNames = QFileDialog::getOpenFileNames(
        this,
        "Open Image Files",
        smCurrentDir.path(),
        Image::openFileFilters(),
        nullptr,
        QFileDialog::ReadOnly);
    foreach (const QString cName, tFileNames)
    {
        FileInfo tFI(cName);
        if (tFI.exists() && tFI.isReadable())
        {
            FNEMITARG("imageOpenDialogFile", tFI, "FileInfo");
            emit imageOpenDialogFile(tFI);
        }
    }
    FNRTNVOID();
}

void irViewMainWindow::viewImage(const Key aKey, const Image aImage)
{
    if ( ! aKey.isEmpty() && ! aImage.isNull())
    {
        const QSize cImageSize = aImage.toQImage().size();
        mpMainLabel = mLabelMap.add(aKey, aImage);
        setWindowTitle(QString("%1: %2")
                           .arg(QApplication::applicationName()
                                , aKey.last()()));
        setMenuBar(mpMenuBar);
        mpMenuBar->show();
        mpMainLabel->show();
        resize(cImageSize);
        mpMainLabel->resize(cImageSize);
        setMenuBar(mpMenuBar);
        mpMenuBar->show();
    }
}

void irViewMainWindow::setupMenus()
{
    FNENTER();
    DUMPQSL(app()->actmgr()->toDebugStrings());

    QMenu * pFileMenu = new QMenu("File", this);
    NEWOBJ(pFileMenu, "QMenu", this);
    pFileMenu->addAction(app()->actmgr()->action("File/OpenFile")->qaction());
    pFileMenu->addAction(app()->actmgr()->action("File/OpenDir")->qaction());
    pFileMenu->addAction(app()->actmgr()->action("File/Close")->qaction());
    pFileMenu->addSeparator();
    pFileMenu->addAction(app()->actmgr()->action("File/Exit")->qaction());
    mpMenuBar->addMenu(pFileMenu);
    setMenuBar(mpMenuBar);
    mpMenuBar->show();
    FNRTNVOID();
}


