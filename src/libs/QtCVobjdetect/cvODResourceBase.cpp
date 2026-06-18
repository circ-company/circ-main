#include "cvODResourceBase.h"


cvODResourceBase::cvODResourceBase() : mType(cvODType::$nullType), mClass(cvODClass::$nullClass) {;}
cvODResourceBase::cvODResourceBase(const cvODType odType, const cvODClass odClass) : mType(odType), mClass(odClass) {;}

