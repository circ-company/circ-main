#include "RYMainWindow.h"
#include "ui_RYMainWindow.h"

RYMainWindow::RYMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RYMainWindow)
{
    ui->setupUi(this);
}

RYMainWindow::~RYMainWindow()
{
    delete ui;
}
