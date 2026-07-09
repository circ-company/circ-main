#pragma once

#include "cvODObjectClass.h"
#include "cvODResourceType.h"

class cvODResourceBase
{
public:
    cvODResourceBase();

protected:
    cvODResourceBase(const cvODResourceType odType, const cvODObjectClass odClass);

private:
    cvODResourceType mType = cvODResourceType::$nullType;
    cvODObjectClass mClass = cvODObjectClass::$nullClass;
};
