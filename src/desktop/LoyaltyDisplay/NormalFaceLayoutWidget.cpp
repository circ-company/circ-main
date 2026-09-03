#include "NormalFaceLayoutWidget.h"

#include <QLabel>

#include <Log.h>
#include <SCRect.h>

const Size NormalFaceLayoutWidget::scmCellSize = Size(128);


NormalFaceLayoutWidget::NormalFaceLayoutWidget(const Point aPt,
                                               QWidget *parentWidget)
    : QWidgetItem(parentWidget)
    , mGridPosition(aPt)
{
    mKey = QString("$Placeholder/x%1/y%2").arg(aPt.col()).arg(aPt.row());
    mpLabel = new QLabel(parentWidget);
    generate();
}

NormalFaceLayoutWidget::NormalFaceLayoutWidget(const Key aKey, const QImage aImage,
                                               QWidget * parentWidget)
    : QWidgetItem(parentWidget)
    , mKey(aKey)
    , mImage(aImage)
{
    mpLabel = new QLabel(parentWidget);
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

void NormalFaceLayoutWidget::generate()
{
    QImage tImage = mImage;
    if (mImage.isNull())
    {
        mPixmap = QPixmap(cellSize());
        mPixmap.fill(QColor::fromString("steelblue"));
    }
    else
    {
        mPixmap = QPixmap::fromImage(mImage.scaled(cellSize(),
                                Qt::KeepAspectRatio));
    }
    CKPOINTER(mpLabel);
    mpLabel->setPixmap(mPixmap);
}
