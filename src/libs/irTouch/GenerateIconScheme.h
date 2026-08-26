#pragma once

#include <QtGlobal>
#include <QFont>
#include <QRgb>
class QVariant;

#include <Color.h>

class GenerateIconScheme
{
public: // ctor
    GenerateIconScheme();
    GenerateIconScheme(const Color aBaseColor,
                       const Color aEdgeColor=Color(Color::GXO, 0xCCCC));

public: // const
    QVariant toVariant() const;
    operator QVariant () const;

public: // static
    static GenerateIconScheme fromVariant(const QVariant &aVar);


public:
    Color       BaseColor;
    Color       BorderColor;
    int         LightnessAdjust=50;
    Color       LightColor;
    Color       DarkColor;
    Color       TextColor;
    Qt::Corner  SunCorner=Qt::Corner::TopLeftCorner;
    int         FontPoints=14;
    QFont       Font=QFont("Helvetica", FontPoints);
};


