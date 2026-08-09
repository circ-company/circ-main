#include "DocParseResult.h"

DocParseResult::DocParseResult(const QDomDocument::ParseResult aQDDPR)
    : cmQDDPR(aQDDPR) {;}

QString DocParseResult::toString() const
{
    return QString("{DocParseResult: %1 (%2,%3)}")
        .arg(message()).arg(row()).arg(col());
}
