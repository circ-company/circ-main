#pragma once

#include <QMainWindow>

#include <QGraphicsGridLayout>
#include <QGraphicsLayout>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QList>

#include <Point.h>
#include <SCRect.h>
#include <Size.h>

class MainWindowImageGallery : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindowImageGallery();

public slots:
    void initialize();
    void setup();
    void showFiles();

signals:
    void initialized();
    void setuped();

public: // non-const
    void showImage(const QImage &aQI);

private:
    QGraphicsScene * mpMainScene=nullptr;
    QGraphicsView * mpMainView=nullptr;
    QGraphicsWidget * mpMainLayoutWidget=nullptr;
    QGraphicsGridLayout * mpMainGridLayout=nullptr;
    QGraphicsPixmapItem * mpBgPixmapItem=nullptr;
    QMap<Point::Sortable, QGraphicsPixmapItem *> mPointImageItemMap;
    SCRect mMainRect;
    SCRect mCellRect;
    SCRect mImageRect;
    Index mImageIndex=0;


/* ========================= PROPERTIES ========================= */
private:
    Size pGalleryPixelSize = Size(960, 800);
    Size pGalleryCells = Size(5, 6);
};
