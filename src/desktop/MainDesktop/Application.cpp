#include "Application.h"

#include <QTimer>
#include <QWidget>

#include "QQMainWindow.h"

Application::Application(int argc, char *argv[])
    : QQApplication(argc, argv)
{
    setObjectName("Application:MainDesk");
}

void Application::run()
{
    qDebug() << Q_FUNC_INFO;
    QList<QWidget *> tWgtList = topLevelWidgets();
    foreach (QWidget * pWgt, tWgtList)
        qDebug() << pWgt->objectName() << pWgt->minimumSize();
    QTimer::singleShot(100, mainWindow(), &QQMainWindow::run);

}
