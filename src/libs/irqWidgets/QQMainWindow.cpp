#include "QQMainWindow.h"

#include <QApplication>

#include <QQApplication.h>

QQMainWindow::QQMainWindow(const Contents cf, QQApplication *qqapp)
    : QMainWindow{nullptr}
    , mpApplication(qqapp)
    , cmContents(cf)
{
    setObjectName("QQMainWindow:" + app()->applicationName());
}

void QQMainWindow::run()
{
    qInfo() << Q_FUNC_INFO;
}

void QQMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    if (cmContents & Grid)  mpMainGrid = new QGridLayout(mpMainWidget);
    if (cmContents & TextEdit)  mpMainEdit = new QQTextEdit(mpMainWidget);
    if (cmContents & TextDocument)  mpMainDoc = new QQTextDocument(mpMainWidget);
    if (cmContents & ImageLabel)  mpMainLabel = new Label(mpMainWidget);
    // TODO LogStderr req grid unless alone
}

void QQMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
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
//        mpMainDoc->setMinimumSize(mMainWinSize);
  //      if (mpMainGrid) mpMainGrid->addWidget(mpMainDoc);
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
}

void QQMainWindow::ready()
{
    qInfo() << Q_FUNC_INFO;
}
