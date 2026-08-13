#include "MainOptions.h"

#include <Log.h>

MainOptions::MainOptions() {;}

AText MainOptions::positional(const KeySeg &aName) const
{
    return mPosValuesMap.value(aName);
}

void MainOptions::applicationDescription(const QString &aDesc)
{
    parser()->setApplicationDescription(aDesc);
}

void MainOptions::addPositional(const KeySeg &aName, const AText &aDesc)
{
    mPositonalNames.append(aName);
    mPosDescMap.insert(aName, aDesc);
}

void MainOptions::positionalSyntax(const KeySeg &aName, const AText &aSyntax)
{
    mPosSyntaxMap.insert(aName, aSyntax);
}

void MainOptions::process(const QCoreApplication &aApp)
{
    MUSTDO(); // TODO MainOptions::process()
}
