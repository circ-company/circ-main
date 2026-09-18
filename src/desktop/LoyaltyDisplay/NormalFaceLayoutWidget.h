#pragma once

#include <QWidgetItem>

#include <QImage>
#include <QPixmap>
class QLabel;
class QPaintEvent;

#include <Color.h>
#include <Key.h>
#include <Point.h>
#include <Size.h>
class LoyaltyDisplayScreen;

class NormalFaceLayoutWidget : public QWidgetItem
{
public: // types
public: // 'tors
    explicit NormalFaceLayoutWidget(LoyaltyDisplayScreen * parent);
    NormalFaceLayoutWidget(const Key &aKey,
                           const QImage &aImage,
                           LoyaltyDisplayScreen * parent);
    ~NormalFaceLayoutWidget();

public: // const (overrides)
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

public: // const
    bool isPlaceholder() const;
    Key key() const;

public: // static const
    static const Size cellSize();

public: // non-const
    void point(const Point aPt);

public: // pointers
    LoyaltyDisplayScreen * screen();

protected: // non-const
    virtual void paintEvent(QPaintEvent * pEvent); // override?

private: // non-const
    void image(const QImage &aImage);

private:
    static const Size scmCellSize;
    LoyaltyDisplayScreen * mpScreen=nullptr;
    QLabel * mpLabel=nullptr;
    Key mKey;
    Point mPoint;
    Color mBgColor0;
    Color mBgColor1;
    Color mBorderColor;
    Color mSelectColor;
    QPixmap mPixmap;
    QImage mImage;
};

inline Key NormalFaceLayoutWidget::key() const { return mKey; }
inline void NormalFaceLayoutWidget::point(const Point aPt) { mPoint = aPt; }
