#include "irViewApplication.h"

#include <QTimer>

int main(int argc, char *argv[])
{
    irViewApplication a(argc, argv);
    QTimer::singleShot(100, &a, &irViewApplication::run);
    return a.exec();
}
