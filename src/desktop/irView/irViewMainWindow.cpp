#include "irViewMainWindow.h"
#include "ui_irViewMainWindow.h"

irViewMainWindow::irViewMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::irViewMainWindow)
{
    ui->setupUi(this);
}

irViewMainWindow::~irViewMainWindow()
{
    delete ui;
}
