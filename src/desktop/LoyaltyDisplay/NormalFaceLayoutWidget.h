#pragma once

#include <QWidgetItem>

#include <QImage>
#include <QPixmap>
class QLabel;

#include <Color.h>
#include <Key.h>
#include <Size.h>

class NormalFaceLayoutWidget : public QWidgetItem
{
public: // types
public: // 'tors
    explicit NormalFaceLayoutWidget(QWidget * parentWidget=0);
    NormalFaceLayoutWidget(const Key &aKey,
                           const QImage &aImage,
                           QWidget * parentWidget=0);
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

public: // static const
    static const Size cellSize();

private: // non-const
    void image(const QImage &aImage);
    void generate(const Color &aBgColor=Color());

private:
    static const Size scmCellSize;
    QLabel * mpLabel=nullptr;
    Key mKey;
    Color mBgColor;
    QPixmap mPixmap;
    QImage mImage;
};
