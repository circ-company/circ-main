#pragma once

#include <QWidget>
#include <QLabel>
#include <QPixmap>

#include <DualMap.h>
#include <Id.h>
#include <Point.h>
#include <Size.h>

class TouchGallery : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(Size CellSize READ cellSize WRITE cellSize FINAL)
    Q_PROPERTY(Size LayoutCells READ layoutCells WRITE layoutCells FINAL)

public:
    TouchGallery(const Id aId, QWidget *parent=nullptr);

public slots:
    virtual void initialize();
    virtual void setup();
    virtual void run();

signals:
    void initialized();
    void setupd();
    void running();

public: // const
    QString name() const;
    Size cellSize() const;
    Size layoutCells() const;

public: // non-const
    void bgColor(const Point aPt, const QColor &aColor);
    void cellSize(const Size aSize);
    void layoutCells(const Size aSize);

private:
    Id cmId;
    QPixmap mGalleryPixmap;
//    DualMap<Point, QPixmap> mPointPixmapDMap;
    QMap<Point::Sortable, QColor> mPointBgColorMap;
    QMap<Point::Sortable, QPixmap> mPointPixmapMap;

private: // =============== Properties ===============
    Size pmCellSize;
    Size pmLayoutCells;
};
