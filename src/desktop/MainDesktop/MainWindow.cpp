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
    emit running();
}

void MainWindow::initialize()
{
    FNENTER();
    QQMainWindow::initialize();
    emit initialized();
}

void MainWindow::setup()
{
    FNENTER();
    QQMainWindow::setup();
    show();
    emit setuped();
}

void MainWindow::ready()
{
    FNENTER();
    QQMainWindow::ready();
    emit readied();
}

