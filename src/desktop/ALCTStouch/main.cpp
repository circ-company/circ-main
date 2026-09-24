/*! @file main.cpp Main for AnLoCuTraS gallery touch screen unit
 */
#include <QLocale>
#include <QObject>
#include <QTranslator>
#include <QTimer>

#include "ATApplication.h"
#include "ATMainWindow.h"
#include "version.h"

int main(int argc, char *argv[])
{
    ATApplication a(argc, argv);
    ATMainWindow w(&a);
    w.setWindowTitle(QObject::tr(LDVER_PRODUCT, "Simulator Title"));
    a.mainWindow(&w);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "ALCTStouch_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }

    QTimer::singleShot(10, &a, &ATApplication::start);
    return ATApplication::exec();
}
