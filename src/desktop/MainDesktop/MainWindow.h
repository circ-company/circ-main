#pragma once

#include <QQMainWindow.h>

#define APP (Application)(qApp)

class MainWindow : public QQMainWindow
{
    Q_OBJECT
public: // types

public: // c'tors
    MainWindow(QQApplication *app);

public slots:
    virtual void run() final;
    virtual void initialize() final;
    virtual void setup() final;
    virtual void ready() final;

signals:
    void running();
    void initialized();
    void setuped();
    void readied();

public: // const

public: // non-const

public: // pointers

private:

};
