#include "ATMainWindow.h"

ATMainWindow::ATMainWindow(ATApplication *pApp)
    : mpApplication(pApp)
{
    setObjectName("ATMainWindow");
}

ATMainWindow::~ATMainWindow() = default;
