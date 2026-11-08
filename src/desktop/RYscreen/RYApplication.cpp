#include "RYApplication.h"

#include <QAction>

#include <Log.h>

RYApplication::RYApplication(int argc, char * argv[])
    : Application(argc, argv)
{
    FNENTER();
    setObjectName("RYApplication");
}

void RYApplication::initialize()
{
    FNENTER();
    Application::initialize();
    FNEMIT("initialized");
    emit initialized();
}

