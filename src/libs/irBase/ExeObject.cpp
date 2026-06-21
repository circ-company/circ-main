#include "ExeObject.h"

#include <QCoreApplication>

ExeObject::ExeObject(const Type aType, const CText aName)
    : QObject{qApp}
    , cmType(aType)
    , cmName(aName)
{
    setObjectName("ExeObject:" + aName());
}
