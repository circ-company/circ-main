#pragma once

#include <QWidgetItem>

#include <QImage>
#include <QPixmap>
class QLabel;

#include <Key.h>
#include <KeyMap.h>
#include <Size.h>

class NormalFaceLayoutWidget : public QWidgetItem
{
public:
    explicit NormalFaceLayoutWidget(const Point aPt, QWidget * parentWidget=0);
    NormalFaceLayoutWidget(const Key aKey,
                           const QImage aImage,
                           QWidget * parentWidget=0);
    ~NormalFaceLayoutWidget();


    QSize sizeHint() const override;
    QSize minimumSize() const override;
    QSize maximumSize() const override;
    Qt::Orientations expandingDirections() const override;
    bool isEmpty() const override;
    void setGeometry(const QRect&) override;
    QRect geometry() const override;
    QWidget *widget() const override;

    bool hasHeightForWidth() const override;
    int heightForWidth(int) const override;
    int minimumHeightForWidth(int) const override;
    QSizePolicy::ControlTypes controlTypes() const override;

public:
    static const Size cellSize();

private:
    void generate();

private:
    static const Size scmCellSize;
    Key mKey;
    Point mGridPosition;
    QLabel * mpLabel=nullptr;
    QPixmap mPixmap;
    QImage mImage;
    static KeyMapT<NormalFaceLayoutWidget *> smKeyItemMap;
};
