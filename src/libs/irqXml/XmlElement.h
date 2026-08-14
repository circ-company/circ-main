#pragma once

#include <QDomElement>

#include <QList>
#include <QMetaType>

#include <Key.h>

class XmlElement : public QDomElement
{

public: // types
    typedef QList<XmlElement> List;

public: // ctors
    XmlElement(const QDomElement &other);

public: // const

public: // non-const

public: // pointers

private:
    Key mElementKey;

public: // QMetaType
    XmlElement() = default;
    ~XmlElement() = default;
    XmlElement(const XmlElement &) = default;
    XmlElement &operator=(const XmlElement &) = default;
    XmlElement & it() { return *this; }
    const XmlElement & it() const { return *this; }
};

Q_DECLARE_METATYPE(XmlElement);

