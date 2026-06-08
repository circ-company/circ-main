#include "Application.h"
#include "MainWindow.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    MainWindow w(&a);
    a.mainWindow(&w);
    w.show();
    QTimer::singleShot(100, &a, &Application::run);
    return a.exec();
}
