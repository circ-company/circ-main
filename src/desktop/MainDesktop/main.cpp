#include "Application.h"
#include "LoyaltyDisplayScreen.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    LoyaltyDisplayScreen w(&a);
    a.mainWindow(&w);
//    w.show();
    QTimer::singleShot(100, &a, &Application::run);
    return a.exec();
}
