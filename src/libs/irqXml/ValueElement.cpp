#include "ValueElement.h"

#include <AText.h>
#include <CText.h>
#include <FileInfo.h>

ValueElement::ValueElement(const XmlElement aElement) { set(aElement); }

bool ValueElement::set(const XmlElement aElement)
{
    bool result = false;
    mElement = aElement;
    const CText cName = element().tagName();
    const CText cType = element().attribute("type");
    const AText cValueAtx = element().attribute("value");

    if (false)  {;}
    else if (CText("bool") == cType)        result |= setBool(cValueAtx);
    else if (CText("AText") == cType)       result |= setAText(cValueAtx);
    else if (CText("FileInfo") == cType)    result |= setFileInfo(cValueAtx);
    else                                    result  = false;

    return result;
}

bool ValueElement::setBool(const AText aValue)
{
    QVariant::setValue(aValue);
    bool tBool = QVariant::toBool();
    QVariant::setValue(tBool);
    return QMetaType::Bool == QVariant::metaType().id();
}

bool ValueElement::setAText(const AText aValue)
{
    QVariant::setValue(aValue);
    QMetaType tMetaType = QMetaType::fromName("AText");
    return tMetaType.id() == QVariant::metaType().id();
}

bool ValueElement::setFileInfo(const AText aValue)
{
    QVariant::setValue(aValue);
    FileInfo tFI = value<FileInfo>();
    QVariant::setValue(tFI);
    QMetaType tMetaType = QMetaType::fromName("FileInfo");
    return tMetaType.id() == QVariant::metaType().id();
}


