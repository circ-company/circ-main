#pragma once

#include <QMetaType>

#include "XmlElement.h"

class XmlElementList : public XmlElement::List
{
public: // types

public: // ctors

public: // const

public: // non-const

public: // pointers

private:
    XmlElement::List mChildElements;

public: // QMetaType
    XmlElementList() = default;
    ~XmlElementList() = default;
    XmlElementList(const XmlElementList &) = default;
    XmlElementList &operator=(const XmlElementList &) = default;
    XmlElementList & it() { return *this; }
    const XmlElementList & it() const { return *this; }
};

Q_DECLARE_METATYPE(XmlElementList);

