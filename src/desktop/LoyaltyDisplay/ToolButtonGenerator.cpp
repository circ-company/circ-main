#include "ToolButtonGenerator.h"

#include <QObject>

#include <Log.h>
#include <ToolButton.h>

#include "LoyaltyDisplayScreen.h"

ToolButtonGenerator::ToolButtonGenerator(LoyaltyDisplayScreen *parent)
    : mpScreen(parent)
    , cmButtonSize(Size(96, 64)), cmLayoutSize(Size(12, 1))
{
}

EightCC ToolButtonGenerator::ecc(const Index aIx) const
{
    return mEccIndexDMap.a(aIx);
}

Index ToolButtonGenerator::galleryIndex(const EightCC aECC) const
{
    return mEccIndexDMap.b(aECC);
}

Point ToolButtonGenerator::galleryPoint(const EightCC aECC) const
{
    return galleryPoint(galleryIndex(aECC));
}

Point ToolButtonGenerator::galleryPoint(const Index aIX) const
{
    return Point(cmLayoutSize, aIX);
}

UText ToolButtonGenerator::name(const EightCC aECC) const
{
    return mEccButtonNameMap.value(aECC);
}

ToolButton * ToolButtonGenerator::button(const EightCC aECC)
{
    if ( ! mEccButtonMap.contains(aECC))
    {
        UText cButtonName = mEccButtonNameMap.value(aECC);
        UText cColorName = mEccColorNameMap.value(aECC);
        mEccButtonMap.insert(aECC, new ToolButton(cButtonName, cColorName));
    }
    return mEccButtonMap.value(aECC);
}

void ToolButtonGenerator::clear()
{
    mEccIndexDMap.clear(),
    mEccButtonNameMap.clear(),
    mEccColorNameMap.clear();
}

void ToolButtonGenerator::initialize()
{
    clear();
    initEccIndexDMap();
    initButtonNames();
    initColorNames();
}

void ToolButtonGenerator::setup()
{
    NEEDDO("Anything?");
}

void ToolButtonGenerator::run()
{
    NEEDDO("Anything?");

}

LoyaltyDisplayScreen *ToolButtonGenerator::screen()
{
    CKPOINTER(mpScreen);
    return mpScreen;
}

void ToolButtonGenerator::initEccIndexDMap()
{
    mEccIndexDMap.insert(EightCC("$null"),   0),
    mEccIndexDMap.insert(EightCC("Home"),    1),
    mEccIndexDMap.insert(EightCC("Capture"), 2),
    mEccIndexDMap.insert(EightCC("Page3"),   3),
    mEccIndexDMap.insert(EightCC("Page4"),   4),
    mEccIndexDMap.insert(EightCC("Page5"),   5),
    mEccIndexDMap.insert(EightCC("Page6"),   6),
    mEccIndexDMap.insert(EightCC("Page7"),   7),
    mEccIndexDMap.insert(EightCC("Page8"),   8),
#ifdef QT_DEBUG
    mEccIndexDMap.insert(EightCC("Test"),    9),
#else
    mEccIndexDMap.insert(EightCC("Page9"),   9),
#endif
    mEccIndexDMap.insert(EightCC("Finish"), 10),
    mEccIndexDMap.insert(EightCC("System"), 11),
    mEccIndexDMap.insert(EightCC("$Count"), 12);
}

void ToolButtonGenerator::initButtonNames()
{
    mEccButtonNameMap.insert(EightCC("$null"),   QObject::tr("Blank",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Home"),    QObject::tr("Home",     "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Capture"), QObject::tr("Capture",  "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Page3"),   QObject::tr("Page3",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Page4"),   QObject::tr("Page4",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Page5"),   QObject::tr("Page5",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Page6"),   QObject::tr("Page6",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Page7"),   QObject::tr("Page7",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Page8"),   QObject::tr("Page8",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Page9"),   QObject::tr("Page9",    "ButtonName"));
    mEccButtonNameMap.insert(EightCC("Finish"),  QObject::tr("Finish",   "ButtonName"));
    mEccButtonNameMap.insert(EightCC("System"),  QObject::tr("System",   "ButtonName"));
    mEccButtonNameMap.insert(EightCC("$Count"),  QObject::tr("Count",    "ButtonName"));
}

void ToolButtonGenerator::initColorNames()
{
    mEccColorNameMap.insert(EightCC("$null"),   QObject::tr("red",      "ColorName"));
    mEccColorNameMap.insert(EightCC("Home"),    QObject::tr("yellow",   "ColorName"));
    mEccColorNameMap.insert(EightCC("Capture"), QObject::tr("green",    "ColorName"));
    mEccColorNameMap.insert(EightCC("Page3"),   QObject::tr("cyan",     "ColorName"));
    mEccColorNameMap.insert(EightCC("Page4"),   QObject::tr("blue",     "ColorName"));
    mEccColorNameMap.insert(EightCC("Page5"),   QObject::tr("magenta",  "ColorName"));
    mEccColorNameMap.insert(EightCC("Page6"),   QObject::tr("lightGray","ColorName"));
    mEccColorNameMap.insert(EightCC("Page7"),   QObject::tr("darkRed",  "ColorName"));
    mEccColorNameMap.insert(EightCC("Page8"),   QObject::tr("darkGreen","ColorName"));
    mEccColorNameMap.insert(EightCC("Page9"),   QObject::tr("black", "ColorName"));
    mEccColorNameMap.insert(EightCC("Finish"),  QObject::tr("darkBlue", "ColorName"));
    mEccColorNameMap.insert(EightCC("System"),  QObject::tr("darkGray", "ColorName"));
    mEccColorNameMap.insert(EightCC("$Count"),  "transparent");
}


// ======================== public static ======================
// ======================== private static ======================




