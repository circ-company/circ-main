QT -= gui
TEMPLATE = lib
DEFINES += IRQXML_LIBRARY

include(../libs.pri)

SOURCES += \
    irqXML.cpp

HEADERS += \
    irqXML_global.h \
    irqXML.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
