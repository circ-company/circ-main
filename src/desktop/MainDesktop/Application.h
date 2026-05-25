#pragma once

#include <QQApplication.h>
#include <QObject>

class Application : public QQApplication
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);

public slots:
    void run();

public: // const

public: // non-const

public: // pointers

private:

};
