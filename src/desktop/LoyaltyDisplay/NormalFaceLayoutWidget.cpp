#include "NormalFaceLayoutWidget.h"

#include <QLabel>
#include <QPainter>

#include <Log.h>
#include <SCRect.h>

const Size NormalFaceLayoutWidget::scmCellSize = Size(128);


NormalFaceLayoutWidget::NormalFaceLayoutWidget(QWidget *parentWidget)
    : QWidgetItem(parentWidget)
    , mpLabel(new QLabel(parentWidget))
{
    generate();
}

NormalFaceLayoutWidget::NormalFaceLayoutWidget(const Key &aKey, const QImage &aImage,
                                               QWidget * parentWidget)
    : QWidgetItem(parentWidget)
    , mpLabel(new QLabel(parentWidget))
    , mKey(aKey)
{
    image(aImage);
    generate();
}

NormalFaceLayoutWidget::~NormalFaceLayoutWidget()
{
#if 0
    if (mpLabel)
    {
        mpLabel->deleteLater();
        mpLabel = nullptr;
    }
#endif
}

QSize NormalFaceLayoutWidget::sizeHint() const
{
    return cellSize();
}

QSize NormalFaceLayoutWidget::minimumSize() const
{
    return cellSize();
}

QSize NormalFaceLayoutWidget::maximumSize() const
{
    return cellSize();
}

Qt::Orientations NormalFaceLayoutWidget::expandingDirections() const
{
    Qt::Orientations result;
    result |= Qt::Orientation::Horizontal;
    result |= Qt::Orientation::Vertical;
    return result;
}

bool NormalFaceLayoutWidget::isEmpty() const
{
    return false;
}

void NormalFaceLayoutWidget::setGeometry(const QRect &)
{
    // Do nothing; our geometry is fixed
}

QRect NormalFaceLayoutWidget::geometry() const
{
    return SCRect(cellSize(), true).toQRect();
}

QWidget *NormalFaceLayoutWidget::widget() const
{
    return mpLabel;
}

bool NormalFaceLayoutWidget::hasHeightForWidth() const
{
    return true;
}

int NormalFaceLayoutWidget::heightForWidth(int) const
{
    return cellSize().height();
}

int NormalFaceLayoutWidget::minimumHeightForWidth(int) const
{
    return cellSize().height();
}

QSizePolicy::ControlTypes NormalFaceLayoutWidget::controlTypes() const
{
    QSizePolicy::ControlTypes result;
    result |= QSizePolicy::ControlType::Frame;
    result |= QSizePolicy::ControlType::Label;
    result |= QSizePolicy::ControlType::ToolButton;
    return result;
}

const Size NormalFaceLayoutWidget::cellSize()
{
    return scmCellSize;
}

void NormalFaceLayoutWidget::image(const QImage &aImage)
{
    mImage = aImage.convertedTo(QImage::Format_ARGB32);
    generate();
}

void NormalFaceLayoutWidget::generate(const Color &aBgColor)
{
    FNENTER();
    FNARG(aBgColor(), "QColor");
    DUMPVAR(mImage);
    CKPOINTER(mpLabel);
    // Background
    if (aBgColor.notNull())
    {
        mBgColor = aBgColor;
    }
    else if (mBgColor.isNull())
    {
        mBgColor.set("steelblue");
    }
    mPixmap = QPixmap(cellSize());
    mPixmap.fill(mBgColor());

    // Image
    if ( ! mImage.isNull())
    {
        SCRect tCellRect(cellSize(), true);
        SCRect tImageRect = tCellRect.added( -16 );
        QPixmap tPixmap = QPixmap::fromImage(mImage.scaled(tImageRect.size(),
                                Qt::KeepAspectRatio));
        QPainter tPainter(&mPixmap);
        tPainter.drawPixmap(tImageRect(), tPixmap);
        tPainter.end();
    }

    // Label
    mpLabel->setPixmap(mPixmap);
    FNRTNVOID();
}
