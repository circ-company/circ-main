#include "Application.h"
#include "irViewMainWindow.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    irViewMainWindow w;
    a.mainWindow(&w);
    QTimer::singleShot(100, &a, &Application::run);
    return a.exec();
}
