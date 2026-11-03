#include "boostLogEngine.h"

#include <QCoreApplication>

boostLogEngine::boostLogEngine()
    : QObject{qApp}
{
    setObjectName("boostLogEngine");
}
