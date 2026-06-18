#pragma once

#include "cvODClass.h"
#include "cvODType.h"

class cvODResourceBase
{
public:
    cvODResourceBase();

protected:
    cvODResourceBase(const cvODType odType, const cvODClass odClass);

private:
    cvODType mType = cvODType::$nullType;
    cvODClass mClass = cvODClass::$nullClass;
};
