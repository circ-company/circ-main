#include "RYApplication.h"
#include "RYMainWindow.h"

int main(int argc, char *argv[])
{
    RYApplication a(argc, argv);
    RYMainWindow w(&a);
    w.show();
    return a.exec();
}
