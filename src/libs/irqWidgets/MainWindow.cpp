#include "MainWindow.h"

#include <QGridLayout>
#include <QStackedLayout>

#include <Application.h>
#include <Log.h>

MainWindow::MainWindow(const Contents cf, Application *qqapp)
    : QMainWindow{nullptr}
    , mpApplication(qqapp)
    , cmContents(cf)
{
    FNENTER();
    setObjectName("QQMainWindow:" + app()->applicationName());
    FNRTNVOID();
}

void MainWindow::run()
{
    FNENTER();
    FNRTNVOID();
}

void MainWindow::initialize()
{
    FNENTER();
    mpMainWidget = new QWidget(this);
    if (cmContents & Grid)  mpMainGrid = new QGridLayout(mpMainWidget);
    if (cmContents & Stack)  mpMainStack = new QStackedLayout(mpMainWidget);
    if (cmContents & TextEdit)  mpMainEdit = new QQTextEdit(mpMainWidget);
    if (cmContents & TextDocument)  mpMainDoc = new QQTextDocument(mpMainWidget);
    if (cmContents & ImageLabel)  mpMainLabel = new Label(mpMainWidget);
    // TODO LogStderr req grid unless alone
    FNRTNVOID();
}

void MainWindow::setup()
{
    FNENTER();
    if (cmContents & TextEdit)
    {
        Q_CHECK_PTR(mpMainEdit);
        mpMainEdit->setMinimumSize(mMainWinSize);
        if (mpMainGrid)
            mpMainGrid->addWidget(mpMainEdit);
    }
    if (cmContents & TextDocument)
    {
        Q_CHECK_PTR(mpMainDoc);
    }
    if (cmContents & ImageLabel)
    {
        Q_CHECK_PTR(mpMainLabel);
        mpMainLabel->setMinimumSize(mMainWinSize);
        if (mpMainGrid)
            mpMainGrid->addWidget(mpMainLabel);
        else
            mpMainWidget = mpMainLabel;
    }
    if (mpMainGrid)
    {
        Q_CHECK_PTR(mpMainWidget);
        mpMainWidget->setLayout(mpMainGrid);
    }
    if (mpMainStack)
    {
        Q_CHECK_PTR(mpMainWidget);
        mpMainWidget->setLayout(mpMainStack);
    }
    Q_CHECK_PTR(mpMainWidget);
    setCentralWidget(mpMainWidget);
    FNRTNVOID();
}

void MainWindow::ready()
{
    FNENTER();
    FNRTNVOID();
}

