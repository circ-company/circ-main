#include "FaceWidget.h"

#include <QList>
#include <QPainter>
#include <QPainterPath>

#include <Log.h>
#include <Point.h>
#include <SCRect.h>
#include <Size.h>
#include <Types.h>

FaceWidget::FaceWidget(QWidget *parent)
    : Label(parent)
{
    mBaseColors = QList<QColor>() << Qt::blue << Qt::darkBlue << Qt::cyan << Qt::darkCyan
                                  << QColor(127, 0, 255) << QColor(127, 127, 255)
                                  << QColor(0, 127, 255);
    mBaseColor = mBaseColors.first();
}

void FaceWidget::dummy(const Index ix)
{
    FNENTER();
    const QColor cColor = (ix < 0) ? baseColor() : mBaseColors[ix % mBaseColors.count()];
    QPixmap tPixmap(baseSize());
    tPixmap.fill(cColor.lighter(130));
    QPainter tPainter(&tPixmap);
    QPainterPath tPath;
    tPath.moveTo(0, 127); tPath.lineTo(63, 63); tPath.lineTo(127, 127); tPath.closeSubpath();
    tPainter.setBrush(cColor.darker(150));
    tPainter.drawPath(tPath);
    tPainter.setBrush(cColor);
    tPainter.drawEllipse(SCRect(Size(64), Point(63, 63)));
    tPainter.end();
    setPixmap(tPixmap);
}
