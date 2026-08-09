QT *= xml
TEMPLATE = lib
DEFINES += IRQXML_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)
include(../../useTypes.pri)
include(../../useStore.pri)


SOURCES += \
    DocParseResult.cpp \
    ValueElement.cpp \
    XmlDocFile.cpp \
    XmlDocObject.cpp \
    XmlElement.cpp \
    XmlElementList.cpp \
    irqXml.cpp

HEADERS += \
    DocParseResult.h \
    ValueElement.h \
    XmlDocFile.h \
    XmlDocObject.h \
    XmlElement.h \
    XmlElementList.h \
    irqXml_global.h \
    irqXml.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Detectors.xml
