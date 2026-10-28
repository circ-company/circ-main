#pragma once

#include <QObject>
#include <Application.h>

class RYApplication : public Application
{
    Q_OBJECT
public:
    RYApplication(int argc, char *argv[]);
};
