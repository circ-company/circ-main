#pragma once

#include <QDomElement>

#include <QMetaType>

#include <List.h>

class XmlElement : public QDomElement
{

public: // types
    typedef ListT<XmlElement> List;

public: // ctors

public: // const

public: // non-const

public: // pointers

private:

public: // QMetaType
    XmlElement() = default;
    ~XmlElement() = default;
    XmlElement(const XmlElement &) = default;
    XmlElement &operator=(const XmlElement &) = default;
    XmlElement & it() { return *this; }
    const XmlElement & it() const { return *this; }
};

Q_DECLARE_METATYPE(XmlElement);

