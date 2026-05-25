#include "QQMainWindow.h"

#include <QApplication>
#include <QApplication>
#include <QApplication>
#include <QApplication>

QQMainWindow::QQMainWindow(const Contents cf, QWidget *parent)
    : QMainWindow{parent}
    , cmContents(cf)
{
    setObjectName("QQMainWindow:"+qApp->applicationName());
}

void QQMainWindow::run()
{
    connect(this, &QQMainWindow::running, this, &QQMainWindow::initialize);
    connect(this, &QQMainWindow::initialized, this, &QQMainWindow::setup);
    connect(this, &QQMainWindow::setuped, this, &QQMainWindow::ready);
    emit running();
}

void QQMainWindow::initialize()
{
    if (cmContents & Grid)  mpMainGrid = new QGridLayout(mpMainWidget);
    if (cmContents & TextEdit)  mpMainEdit = new QQTextEdit(mpMainWidget);
    if (cmContents & TextDocument)  mpMainDoc = new QQTextDocument(mpMainWidget);
    if (cmContents & (ImageLabel | TextLabel))  mpMainLabel = new Label(mpMainWidget);
    // TODO LogStderr req grid unless alone
    emit initialized();
}

void QQMainWindow::setup()
{
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
    if (cmContents & (ImageLabel | TextLabel))
    {
        Q_CHECK_PTR(mpMainLabel);
        mpMainLabel->setMinimumSize(mMainWinSize);
        if (mpMainGrid)
            mpMainGrid->addWidget(mpMainLabel);
        else
            mpMainWidget = mpMainEdit;
    }
    if (mpMainGrid)
    {
        mpMainWidget = new QWidget(this);
        Q_CHECK_PTR(mpMainWidget);
        mpMainWidget->setLayout(mpMainGrid);
    }
    Q_CHECK_PTR(mpMainWidget);
    setCentralWidget(mpMainWidget);
    emit setuped();
}

void QQMainWindow::ready()
{
    qInfo() << Q_FUNC_INFO;
}
