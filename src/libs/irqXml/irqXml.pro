QT *= xml
TEMPLATE = lib
DEFINES += IRQXML_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useTypes.pri)
include(../../useStore.pri)


SOURCES += \
    XmlDocument.cpp \
    XmlElement.cpp \
    XmlElementList.cpp \
    irqXml.cpp

HEADERS += \
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
