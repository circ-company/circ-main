#include "GenerateIconScheme.h"

#include <QObject>
#include <QVariant>

#include <Log.h>

GenerateIconScheme::GenerateIconScheme() {;}

GenerateIconScheme::GenerateIconScheme(const Color aBaseColor,
                                       const Color aEdgeColor)
{
    BaseColor   = aBaseColor.lighter(250);
    BorderColor = aBaseColor.darker(250);
    LightColor  = aEdgeColor.lighter(500);
    DarkColor   = aEdgeColor.darker(500);
    TextColor   = aBaseColor.inverted();
    SunCorner   = Qt::TopLeftCorner;
    Font        = QFont(QObject::tr("Helvetica","ButtonFont"));
    FontPoints  = 18;
}

QVariant GenerateIconScheme::toVariant() const
{
    QVariant result;
    MUSTDO();
    return result;
}

GenerateIconScheme::operator QVariant() const { return toVariant(); }

GenerateIconScheme cfromVariant(const QVariant &aVar)
{
    GenerateIconScheme result;
    MUSTDO(); Q_UNUSED(aVar);
    return result;
}


