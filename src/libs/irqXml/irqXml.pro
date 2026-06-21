QT *= xml
TEMPLATE = lib
DEFINES += IRQXML_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useTypes.pri)
include(../../useStore.pri)


SOURCES += \
    ValueElement.cpp \
    XmlDocument.cpp \
    XmlElement.cpp \
    XmlElementList.cpp \
    irqXml.cpp

HEADERS += \
    ValueElement.h \
    XmlDocument.h \
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
