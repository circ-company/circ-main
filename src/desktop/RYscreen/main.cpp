#include "RYMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RYMainWindow w;
    w.show();
    return a.exec();
}
