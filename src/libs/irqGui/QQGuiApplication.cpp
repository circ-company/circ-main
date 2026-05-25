#include "QQGuiApplication.h"

QQGuiApplication::QQGuiApplication(int &argc, char **argv)
    : QGuiApplication(argc, argv)
{
    setObjectName("QQGuiApplication");
}
