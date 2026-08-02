#include "MainWindow.h"

#include "Log.h"

MainWindow::MainWindow(QQApplication *app)
    : QQMainWindow(QQMainWindow::ImageLabel, app)
{
    setObjectName("MainWindow");
}

void MainWindow::run()
{
    FNENTER();
    QQMainWindow::run();
    connect(this, &QQMainWindow::running, this, &QQMainWindow::initialize);
    connect(this, &QQMainWindow::initialized, this, &QQMainWindow::setup);
    connect(this, &QQMainWindow::setuped, this, &QQMainWindow::ready);
    FNEMIT(running());
    emit running();
    FNRTNVOID();
}

void MainWindow::initialize()
{
    FNENTER();
    QQMainWindow::initialize();
    FNEMIT(initialized());
    emit initialized();
    FNRTNVOID();
}

void MainWindow::setup()
{
    FNENTER();
    QQMainWindow::setup();
    show();
    FNEMIT(setuped());
    emit setuped();
    FNRTNVOID();
}

void MainWindow::ready()
{
    FNENTER();
    QQMainWindow::ready();
    FNEMIT(readied());
    emit readied();
    FNRTNVOID();
}

