#include "Application.h"
#include "MainWindow.h"

#include <QTimer>

#define DOCTEST_CONFIG_IMPLEMENT
#include "../../../doctest/doctest/doctest.h"

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    MainWindow w(&a);
    a.mainWindow(&w);
    w.show();
    QTimer::singleShot(100, &a, &Application::run);
    return a.exec();
}
