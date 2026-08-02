#include "QQApplication.h"

#include <Log.h>

QQApplication::QQApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    mArguments.set(arguments());
    mExeInfo.setFile(mArguments.takeFirst());
    setObjectName("QQApplication:" + exeInfo().completeBaseName());
}

void QQApplication::run()
{
    FNENTER();

    FNRTNVOID();
}

void QQApplication::initialize()
{
    FNENTER();

    FNRTNVOID();
}

void QQApplication::setup()
{
    FNENTER();

    FNRTNVOID();
}

void QQApplication::start()
{
    FNENTER();

    FNRTNVOID();
}

void QQApplication::processFile()
{
    FNENTER();

    FNRTNVOID();
}





