#include "XmlDocObject.h"

XmlDocObject::XmlDocObject(QObject *parent)
    : QObject{parent}
{
    setObjectName("XmlDocObject");
}

void XmlDocObject::clear()
{

}

void XmlDocObject::set(const FileInfo &aFileInfo)
{

}

void XmlDocObject::set(const FSText &aFilePathName, QObject *parent)
{

}

void XmlDocObject::set(const QDir &aDir, const QString &aFileName, QObject *parent)
{

}

void XmlDocObject::read(const FileInfo &aFileInfo)
{

}

void XmlDocObject::read()
{

}

void XmlDocObject::startParse()
{

}

void XmlDocObject::parseNext()
{

}
