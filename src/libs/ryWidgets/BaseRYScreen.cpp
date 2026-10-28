#include "BaseRYScreen.h"

#include <MainWindow.h>

BaseRYScreen::BaseRYScreen(MainWindow *parent)
    : QWidget{parent}
{
    setObjectName("BaseRYScreen");
}
