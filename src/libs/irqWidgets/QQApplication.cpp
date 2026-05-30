#include "QQApplication.h"

QQApplication::QQApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    mArguments.set(arguments());
    mExeInfo.setFile(mArguments.takeFirst());
    setObjectName("QQApplication:" + exeInfo().completeBaseName());
}

void QQApplication::run()
{

}

void QQApplication::initialize()
{

}

void QQApplication::start()
{

}

void QQApplication::processFile(const FileInfo fi)
{

}





