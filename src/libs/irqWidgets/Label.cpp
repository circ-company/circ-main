#include "Label.h"

#include <QPainter>

#include <Aspect.h>
#include <Log.h>
#include <SCRect.h>

Label::Label(QWidget *parent) : QLabel{parent} {;}
Label::Label(const QString &text, QWidget *parent) : QLabel(text, parent) {;}
Label::Label(const BYTE digits, QWidget *parent) : QLabel(QString(digits, '0'), parent) { clear(); }
Label::Label(const QPixmap &pxm, QWidget *parent, const QString &text) : QLabel(text, parent) { setPixmap(pxm); }
Label::Label(const QImage &img, QWidget *parent, const QString &text)  : QLabel(text, parent) { setPixmap(QPixmap::fromImage(img)); }
Label::Label(const Size sz, const QColor &clr, QWidget *parent) : QLabel(parent) { set(sz, clr); }
Label::Label(const Size sz, const QImage &img, QWidget *parent, const QString &text)
    : QLabel(text, parent) { set(sz, img); }

void Label::set(const QString &s)
{
    QLabel::setText(s);
}

void Label::set(const QPixmap &pxm)
{
    QLabel::setPixmap(pxm);
}

void Label::set(const QImage &img)
{
    set(mImageSize, img);
}

void Label::set(const Size sz, const QColor &clr)
{
    FNENTER();
    FNARG(sz, Size);
    QPixmap tPixmap(sz);
    tPixmap.fill(clr);
    set(tPixmap);
}

void Label::set(const Size displaySize, const QImage &img)
{
    FNENTER();
    FNARG(displaySize, Size);
    const Size cOrigSize = img.size();
    DUMPVAR(cOrigSize);
    DUMPVAR(img.format());
    const Aspect cOriginalAspect = cOrigSize.aspect();
    const Size cAspectSize(displaySize, cOriginalAspect);
    const SCRect cCenteredRect(cAspectSize);
    const QRect cPaintRect(cCenteredRect.toQRect());
    const qreal cScaleF = cAspectSize.scaleToF(size());
    resize(displaySize);
    QPixmap tPixmap(displaySize);
    QPainter tPainter;
    tPainter.begin(&tPixmap);
    tPainter.fillRect(SCRect(displaySize).toQRect(), mBackColor);
    tPainter.drawImage(cPaintRect, img.scaled(cAspectSize * cScaleF));
    tPainter.end();
    set(tPixmap);
}



