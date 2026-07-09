#include "cvODResourceBase.h"


cvODResourceBase::cvODResourceBase() : mType(cvODResourceType::$nullType), mClass(cvODObjectClass::$nullClass) {;}
cvODResourceBase::cvODResourceBase(const cvODResourceType odType, const cvODObjectClass odClass) : mType(odType), mClass(odClass) {;}

