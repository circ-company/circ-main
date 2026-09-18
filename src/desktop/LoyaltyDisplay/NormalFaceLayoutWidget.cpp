#include "NormalFaceLayoutWidget.h"

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>

#include <Log.h>
#include <SCRect.h>

#include "LoyaltyDisplayScreen.h"

const Size NormalFaceLayoutWidget::scmCellSize = Size(160);

NormalFaceLayoutWidget::
        NormalFaceLayoutWidget(LoyaltyDisplayScreen *parent)
    : QWidgetItem(parent)
    , mpScreen(parent)
    , mpLabel(new QLabel(parent))
    , mBgColor0(Color("skyblue"))
    , mBgColor1(Color("steelblue"))
{
}

NormalFaceLayoutWidget::
    NormalFaceLayoutWidget(const Key &aKey,
                           const QImage &aImage,
                           LoyaltyDisplayScreen *parent)
    : QWidgetItem(parent)
    , mpScreen(parent)
    , mpLabel(new QLabel(parent))
    , mKey(aKey)
    , mBgColor0(Color("skyblue"))
    , mBgColor1(Color("steelblue"))
{
    image(aImage);
}

NormalFaceLayoutWidget::~NormalFaceLayoutWidget()
{
    if (mpLabel)
    {
        mpLabel->deleteLater();
        mpLabel = nullptr;
    }
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

LoyaltyDisplayScreen *NormalFaceLayoutWidget::screen()
{
    CKPOINTER(mpScreen);
    return mpScreen;
}

void NormalFaceLayoutWidget::paintEvent(QPaintEvent *pEvent)
{
    FNENTER();
    CKPOINTER(pEvent);
    FNARG(pEvent->rect(), "QRect");
    SCRect tOuterRect(screen()->faceSize());
    SCRect tBgRect = tOuterRect.expanded(-4);
    SCRect tBorderRect = tOuterRect.expanded(-8);
    SCRect tFaceRect = tBorderRect.expanded(-8);
    EXPECTEQ(Size(128), tFaceRect.size());

    QPainter tPainter(mpLabel);
    tPainter.fillRect(tOuterRect(), Qt::transparent);
    tPainter.fillRect(tBgRect(),
                      (mPoint.index(screen()->faceLayout()) % 2)
                          ? mBgColor0() : mBgColor1());
    tPainter.fillRect(tBorderRect(), mBorderColor());
    tPainter.drawImage(tFaceRect(), mImage.scaled(Size(128)(),
                    Qt::AspectRatioMode::KeepAspectRatio));
    tPainter.end();
    FNRTNVOID();
}

void NormalFaceLayoutWidget::image(const QImage &aImage)
{
    mImage = aImage.convertedTo(QImage::Format_ARGB32);
}

