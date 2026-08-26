#include "GenerateIcon.h"

#include <Log.h>

GenerateIcon::GenerateIcon(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("GenerateIcon");
}

GenerateIcon::GenerateIcon(const Size aSize, QWidget *parent)
    : QWidget{parent}
    , mSize(aSize)
{
    setObjectName("GenerateIcon");
}

GenerateIcon::GenerateIcon(const GenerateIconScheme aScheme,
                           QWidget *parent)
    : QWidget{parent}
    , mScheme(aScheme)
{
    setObjectName("GenerateIcon");
}

GenerateIcon::GenerateIcon(const Size aSize,
                           const GenerateIconScheme aScheme,
                           QWidget *parent)
    : QWidget{parent}
    , mSize(aSize)
    , mScheme(aScheme)
{
    setObjectName("GenerateIcon");
}

void GenerateIcon::set(const Size aSize)
{
    FNENTER();
    FNARG(aSize, "Size");
    mSize = aSize;
    FNEMITARG("sizeSet", mSize, "Size");
    emit sizeSet(mSize);
    FNRTNVOID();
}

void GenerateIcon::set(const GenerateIconScheme aScheme)

{
    FNENTER();
    FNARG(aScheme, "GenerateIconScheme");
    mScheme = aScheme;
    FNEMITARG("schemeSet", mScheme, "Scheme");
    emit schemeSet(mScheme);
    FNRTNVOID();
}

void GenerateIcon::generate(const Size aSize, const UText &aText)
{
    FNENTER();
    FNARG(aSize, "Size");
    FNARG(aText, "UText");
    set(aSize);
    generate(aText);
    FNRTNVOID();
}

void GenerateIcon::generate(const GenerateIconScheme &aScheme,
                            const UText &aText)
{
    FNENTER();
    FNARG(aScheme, "GenerateIconScheme");
    FNARG(aText, "UText");
    set(aScheme);
    generate(aText);
    FNRTNVOID();
}

void GenerateIcon::generate(const Size aSize,
                            const GenerateIconScheme &aScheme,
                            const UText &aText)
{
    FNENTER();
    FNARG(aSize, "Size");
    FNARG(aScheme, "GenerateIconScheme");
    set(aSize);
    set(aScheme);
    generate(aText);
    FNRTNVOID();
}

void GenerateIcon::generate(const UText &aText)
{
    FNENTER();
    FNARG(aText, "UText");
    const QPixmap cPixmapNormalOn = makeNormalOn(aText);
    const QPixmap cPixmapDisableOn = makeDisableOn(aText);
    const QPixmap cPixmapActiveOn = makeActiveOn(aText);
    const QPixmap cPixmapSelectOn = makeSelectOn(aText);
    const QPixmap cPixmapNormalOff = makeNormalOff(aText);
    const QPixmap cPixmapDisableOff = makeDisableOff(aText);
    const QPixmap cPixmapActiveOff = makeActiveOff(aText);
    const QPixmap cPixmapSelectOff = makeSelectOff(aText);
    mIcon = QIcon();
    mIcon.addPixmap(cPixmapNormalOn, QIcon::Normal, QIcon::On);
    mIcon.addPixmap(cPixmapDisableOn, QIcon::Disabled, QIcon::On);
    mIcon.addPixmap(cPixmapActiveOn, QIcon::Active, QIcon::On);
    mIcon.addPixmap(cPixmapSelectOn, QIcon::Selected, QIcon::On);
    mIcon.addPixmap(cPixmapNormalOff, QIcon::Normal, QIcon::Off);
    mIcon.addPixmap(cPixmapDisableOff, QIcon::Disabled, QIcon::Off);
    mIcon.addPixmap(cPixmapActiveOff, QIcon::Active, QIcon::Off);
    mIcon.addPixmap(cPixmapSelectOff, QIcon::Selected, QIcon::Off);
    FNEMITARG("generated", mIcon, "QIcon");
    emit generated(mIcon);
    FNRTNVOID();
}



QPixmap GenerateIcon::makeNormalOn(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::makeDisableOn(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    tScheme.BaseColor.greyify();
    tScheme.BorderColor.greyify();
    tScheme.LightColor.greyify();
    tScheme.DarkColor.greyify();
    tScheme.TextColor.greyify();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::makeActiveOn(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::makeSelectOn(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::makeNormalOff(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::makeDisableOff(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::makeActiveOff(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::makeSelectOff(const UText &aText)
{
    GenerateIconScheme tScheme = scheme();
    return draw(aText, tScheme);
}

QPixmap GenerateIcon::draw(const UText &aText,
                           const GenerateIconScheme &aScheme)
{
    QPixmap result;
    MUSTDO();
    return result;
}
