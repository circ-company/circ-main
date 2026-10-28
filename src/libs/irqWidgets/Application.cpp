#include "Application.h"

#include <Log.h>

Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
{
    mArguments.set(arguments());
    mExeInfo.setFile(mArguments.takeFirst());
    setObjectName("QQApplication:" + exeInfo().completeBaseName());
}

void Application::run()
{
    FNENTER();

    FNRTNVOID();
}

void Application::initialize()
{
    FNENTER();

    FNRTNVOID();
}

void Application::setup()
{
    FNENTER();

    FNRTNVOID();
}

void Application::start()
{
    FNENTER();

    FNRTNVOID();
}

void Application::processFile()
{
    FNENTER();

    FNRTNVOID();
}





