#include "QQMainWindow.h"

#include <QQApplication.h>
#include <Log.h>

QQMainWindow::QQMainWindow(const Contents cf, QQApplication *qqapp)
    : QMainWindow{nullptr}
    , mpApplication(qqapp)
    , cmContents(cf)
{
    FNENTER();
    setObjectName("QQMainWindow:" + app()->applicationName());
    FNRTNVOID();
}

void QQMainWindow::run()
{
    FNENTER();
    FNRTNVOID();
}

void QQMainWindow::initialize()
{
    FNENTER();
    if (cmContents & Grid)  mpMainGrid = new QGridLayout(mpMainWidget);
    if (cmContents & TextEdit)  mpMainEdit = new QQTextEdit(mpMainWidget);
    if (cmContents & TextDocument)  mpMainDoc = new QQTextDocument(mpMainWidget);
    if (cmContents & ImageLabel)  mpMainLabel = new Label(mpMainWidget);
    // TODO LogStderr req grid unless alone
    FNRTNVOID();
}

void QQMainWindow::setup()
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
        mpMainWidget = new QWidget(this);
        Q_CHECK_PTR(mpMainWidget);
        mpMainWidget->setLayout(mpMainGrid);
    }
    Q_CHECK_PTR(mpMainWidget);
    setCentralWidget(mpMainWidget);
    FNRTNVOID();
}

void QQMainWindow::ready()
{
    FNENTER();
    FNRTNVOID();
}

