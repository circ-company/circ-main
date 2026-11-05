#include "ryFaceGrid.h"

#include <QColor>
#include <QGridLayout>
#include <QList>
#include <QPainter>
#include <QPainterPath>

#include <Log.h>
#include <Point.h>
#include <SCRect.h>
#include <Size.h>
#include <Types.h>

ryFaceGrid::ryFaceGrid(QWidget *parent)
    : QWidget(parent)
{
    FNENTER();
    setObjectName("ryFaceGrid");
}

void ryFaceGrid::initialize()
{
    FNENTER();
    mpLayout = new QGridLayout;
    layout()->setObjectName("ryFaceGrid::layout");
}

void ryFaceGrid::setup()
{
    FNENTER();
    QList<QColor> tColorList;
    tColorList << QColor(qRgb(  0,   0, 255)) << QColor(qRgb(127,   0, 255))
               << QColor(qRgb(  0, 127, 255)) << QColor(qRgb(127, 127, 255))
               << QColor(qRgb( 63,   0, 255)) << QColor(qRgb(  0,  63, 255))
               << QColor(qRgb( 63,  63, 255));
    const Count cGridCount = gridElements().area();
    for (Index ix = 0; ix < Index(cGridCount); ++ix)
    {
        const QColor cColor = tColorList.at(ix % tColorList.count());
        const Point cPoint = gridElements().position(ix);
        DUMPVAR(cColor.name());
        DUMPVAR(cPoint.toDebugString());
        layout()->addWidget(dummy(cColor), cPoint.row(), cPoint.col());
    }
    setLayout(layout());
}

Label * ryFaceGrid::dummy(const QColor aBaseColor)
{
    FNENTER();
    Label * result = new Label(this);
    QPixmap tPixmap(Size(128));
    tPixmap.fill(aBaseColor.lighter(130));
    QPainter tPainter(&tPixmap);
    QPainterPath tPath;
    tPath.moveTo(0, 127); tPath.lineTo(63, 63); tPath.lineTo(127, 127); tPath.closeSubpath();
    //tPainter.fillRect(tPixmap.rect(), aBaseColor.lighter(300));
    tPainter.setBrush(aBaseColor.darker(150));
    tPainter.drawPath(tPath);
    tPainter.setBrush(aBaseColor);
    tPainter.drawEllipse(SCRect(Size(64), Point(63, 63)));
    tPainter.end();
    result->setPixmap(tPixmap);
    return result;
}
