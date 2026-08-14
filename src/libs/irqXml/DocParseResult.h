#pragma once

#include <QDomDocument>

#include <Point.h>
#include <Types.h>

class DocParseResult
{
public: // ctors
    DocParseResult(const QDomDocument::ParseResult aQDDPR);

public: // const
    bool ok() const;
    INT row() const;
    INT col() const;
    Point point() const;
    QString message() const;
    QString toString() const;
    operator bool () const;
    operator QString () const;

public: // non-const

private:
    const QDomDocument::ParseResult cmQDDPR;
};

inline bool DocParseResult::ok() const { return bool(cmQDDPR); }
inline INT DocParseResult::row() const { return cmQDDPR.errorLine; }
inline INT DocParseResult::col() const { return cmQDDPR.errorColumn; }
inline Point DocParseResult::point() const { return Point(row(), col()); }
inline QString DocParseResult::message() const { return cmQDDPR.errorMessage; }
inline DocParseResult::operator bool() const { return ok(); }
inline DocParseResult::operator QString() const { return toString(); }
