#pragma once

#include <QVariant>

#include <QMetaType>

#include <AText.h>

#include "XmlElement.h"

class ValueElement : public QVariant
{
public: // ctors
    ValueElement(const XmlElement aElement);

public: // const
    XmlElement element() const;

public: // non-const
    bool set(const XmlElement aElement);

private: // non-const
    bool setBool(const AText aValue);
    bool setAText(const AText aValue);
    bool setFileInfo(const AText aValue);

private:
    XmlElement mElement;
};

inline XmlElement ValueElement::element() const { return mElement; }
