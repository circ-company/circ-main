#pragma once

#include <MainWindow.h>

class RYApplication;

class RYMainWindow : public MainWindow
{
    Q_OBJECT

public: // ctors
    RYMainWindow(RYApplication *parent);
    ~RYMainWindow();

private:
};
