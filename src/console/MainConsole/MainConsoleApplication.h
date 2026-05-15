#pragma once

#include <QQCoreApplication.h>

class MainConsoleApplication : public QQCoreApplication
{
    Q_OBJECT
public:
    MainConsoleApplication(int &argc, char **argv);

public slots:
    void run();
    void initialize();
    void intro();
    void versions();
    void timerStart(const Milliseconds ms, QTimer * pt);
    void timerKill(const Milliseconds ms, QTimer * pt);

signals:
    void running();
    void introed();
    void versioned();

};
