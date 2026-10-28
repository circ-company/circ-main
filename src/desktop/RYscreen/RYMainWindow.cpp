#include "RYMainWindow.h"

#include "RYApplication.h"

RYMainWindow::RYMainWindow(RYApplication *parent)
    : MainWindow(MainWindow::Stack, parent)
{
    setObjectName("RYMainWindow");
}

RYMainWindow::~RYMainWindow()
{
}
