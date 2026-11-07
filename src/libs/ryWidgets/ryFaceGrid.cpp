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

#include "FaceWidget.h"

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
    const Count cGridCount = gridElements().area();
    for (Index ix = 0; ix < Index(cGridCount); ++ix)
    {
        const Point cPoint = gridElements().position(ix);
        DUMPVAR(cPoint.toDebugString());
        FaceWidget * pDummyFace = new FaceWidget(parentWidget());
        pDummyFace->dummy(ix);
        layout()->addWidget(pDummyFace, cPoint.row(), cPoint.col());
    }
    setLayout(layout());
}
