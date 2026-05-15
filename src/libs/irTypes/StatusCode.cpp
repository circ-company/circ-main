#include "StatusCode.h"

bool StatusCode::isNull() const
{
    return 0 == NSTimeStamp() && 0 == SeverityCode();
}


DEFINE_DATAPROPS(StatusCode, StatusCodeData)

void StatusCode::ctor(void) { NSTimeStamp(NanosecondTime::current()); }
void StatusCode::dtor(void) {;}


