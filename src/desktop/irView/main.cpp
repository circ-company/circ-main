#include "Application.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    QTimer::singleShot(100, &a, &Application::run);
    return a.exec();
}
