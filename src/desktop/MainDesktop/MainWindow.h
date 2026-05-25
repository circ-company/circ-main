#pragma once

#include <QQMainWindow.h>

#include "Application.h"

#define APP (Application)(qApp)

class MainWindow : public QQMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:

private:
};
