#include "TouchGallery.h"

#include <QTimer>

#include <Log.h>

TouchGallery::TouchGallery(const Id aId, QWidget *parent)
    : QLabel{parent}
    , cmId(aId)
{
    setObjectName("TouchGallery:" + name());
    QTimer::singleShot(100, this, SLOT(initialize));
}

void TouchGallery::initialize()
{
    FNENTER();
    WASSERT(connect(this, SIGNAL(initialized), this, SLOT(setup)));
    WASSERT(connect(this, SIGNAL(setupd), this, SLOT(run)));
    FNEMIT("initialized")
    emit initialized();
    FNRTNVOID();
}

void TouchGallery::setup()
{
    FNENTER();

    FNEMIT("initialized")
    emit initialized();
    FNRTNVOID();
}

void TouchGallery::run()
{
    FNENTER();

    FNEMIT("initialized")
    emit initialized();
    FNRTNVOID();
}

QString TouchGallery::name() const
{
    return cmId.name();
}

void TouchGallery::bgColor(const Point aPt, const QColor &aColor)
{
    mPointBgColorMap.insert(aPt.sortable(), aColor);
}
