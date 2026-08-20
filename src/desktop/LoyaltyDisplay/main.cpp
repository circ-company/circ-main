/*! @file main.cpp Main for AnLoCuTraS touch screen unit
 */
#include <QApplication>
#include <QLocale>
#include <QTimer>
#include <QTranslator>

#include "LoyaltyDisplayScreen.h"
#include "LoyaltyDisplayBackend.h"

int main(int argc, char *argv[])
{
    LoyaltyDisplayBackend a(argc, argv);
    LoyaltyDisplayScreen w(&a);
    a.screen(&w);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "LoyaltyDisplay_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    w.show();
    QTimer::singleShot(10, &a, &LoyaltyDisplayBackend::start);
    return QApplication::exec();
}
