#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QQMainWindow(Contents(QQMainWindow::Grid
                         | QQMainWindow::TextEdit
                         | QQMainWindow::LogStderr),
                   parent)
{
    setObjectName("MainWindow");
}

MainWindow::~MainWindow() {;}
