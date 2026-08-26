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
                       const Color aEdgeColor=Color(Color::GXO, 0xC080));

public: // const
    QVariant toVariant() const;
    operator QVariant () const;

public: // static
    static GenerateIconScheme fromVariant(const QVariant &aVar);


public:
    Color       BaseColor;
    Color       BorderColor;
    Color       LightColor;
    Color       DarkColor;
    Color       TextColor;
    Qt::Corner  SunCorner;
    QFont       Font;
    int         FontPoints;

};


