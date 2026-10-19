#include "LoyaltyDisplayScreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoyaltyDisplayScreen w;
    w.show();
    return a.exec();
}
