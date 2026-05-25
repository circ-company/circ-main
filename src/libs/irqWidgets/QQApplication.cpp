#include "QQApplication.h"

QQApplication::QQApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setObjectName("QQApplication:" + arguments().first());
}
