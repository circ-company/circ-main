#pragma once

#include <QGuiApplication>

class QQGuiApplication : public QGuiApplication
{
protected:
    QQGuiApplication(int &argc, char **argv);
};
