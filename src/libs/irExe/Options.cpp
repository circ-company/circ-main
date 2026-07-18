#include "Options.h"

#include <TriBool.h>

Options::Options(ExeSupport *pExe)
    : mpExeSupport(pExe)
{

}

bool Options::add(const Option &aOpt, const bool aOverride)
{
    TriBool result;
    const KeySeg cName = aOpt.name();
    if (contains(cName) && aOverride)
        result.expect(remove(cName));
    if ( ! contains(cName) || aOverride)
    {
        mNameOptionMap.insert(cName, aOpt);
        result.set();
    }
    return result;
}

bool Options::remove(const KeySeg &aName)
{
    bool result = contains(aName);
    if (result) mNameOptionMap.remove(aName);
    return result;
}

