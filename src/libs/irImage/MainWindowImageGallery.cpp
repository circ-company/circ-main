#include "MainWindowImageGallery.h"

#include <QApplication>
#include <QLabel>

#include <Log.h>

MainWindowImageGallery::MainWindowImageGallery()
    : QMainWindow{nullptr}
{
    setObjectName("MainWindowImageGallery");
    ASSERT(connect(this, &MainWindowImageGallery::initialized,
                   this, &MainWindowImageGallery::setup));
    ASSERT(connect(this, &MainWindowImageGallery::setuped,
                   this, &MainWindowImageGallery::showFiles));
}

void MainWindowImageGallery::initialize()
{
    FNENTER();
    mpMainScene = new QGraphicsScene;
    NEWOBJ(mpMainScene, "QGraphicsScene", nullptr);
    mpMainView = new QGraphicsView(mpMainScene);
    NEWOBJ(mpMainView, "QGraphicsView", mpMainScene);
    mpMainLayoutWidget = new QGraphicsWidget;
    NEWOBJ(mpMainLayoutWidget, "QGraphicsWidget", nullptr);
    mpMainGridLayout = new QGraphicsGridLayout;
    CKPOINTER(mpMainGridLayout);
    FNEMIT("initialized");
    emit initialized();
    FNRTNVOID();
}

void MainWindowImageGallery::setup()
{
    FNENTER();

    setMinimumSize(pGalleryPixelSize + 64);
    showNormal();

    QPen tPen(Qt::black, 3);
    QBrush tBrush(QColor("khaki"));
    mMainRect = SCRect(pGalleryPixelSize, false);
    mpMainView->setSceneRect(mMainRect());
    mpMainView->setUpdatesEnabled(true);
    mpMainScene->addRect(mMainRect(), tPen, tBrush);

    mCellRect.set(Size(160));
    QPixmap tBgPixmap(mCellRect.size()());
    for (Index ix = 0; ix < pGalleryCells.area(); ++ix)
    {
        Point tCellPt(pGalleryCells, ix);
        tBgPixmap.fill(((tCellPt.row() + tCellPt.col()) % 2)
                ? QColor("skyblue") : QColor("steelblue"));
        QGraphicsPixmapItem * pItem = new QGraphicsPixmapItem(tBgPixmap);
        mpMainScene->addItem(pItem);
        pItem->moveBy((pGalleryPixelSize.width()  / - 2)
                          + tCellPt.row() * mCellRect.width(),
                      (pGalleryPixelSize.height() / - 2)
                          + tCellPt.col() * mCellRect.height());
        mPointImageItemMap.insert(tCellPt.sortable(), pItem);
    }

    setCentralWidget(mpMainView);
    mpMainView->update();
    mpMainView->repaint();
    QApplication::processEvents();

    FNEMIT("setuped");
    emit setuped();
    FNRTNVOID();
}

void MainWindowImageGallery::showFiles()
{

}

void MainWindowImageGallery::showImage(const QImage &aQI)
{
    Index ix = mImageIndex++;
    Point tCellIndexPt = Point(pGalleryCells, ix);
    mImageRect.set(Size(128));

    QPixmap tPixmap = QPixmap::fromImage(aQI.scaled(mCellRect.size()(),
                Qt::AspectRatioMode::KeepAspectRatio));
    QGraphicsPixmapItem * pItem = new QGraphicsPixmapItem(tPixmap);
    CKPOINTER(pItem);
    mpMainScene->addItem(pItem);

    Point tCellPt(tCellIndexPt.x() % pGalleryCells.width(),
                  tCellIndexPt.y() % pGalleryCells.height());
    pItem->moveBy((pGalleryPixelSize.width()  / - 2)
                      + tCellPt.row() * mCellRect.width(),
                  (pGalleryPixelSize.height() / - 2)
                      + tCellPt.col() * mCellRect.height());
    mpMainView->update();
    mpMainView->repaint();
    QApplication::processEvents();
}
