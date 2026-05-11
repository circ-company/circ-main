QT += gui
TEMPLATE = lib
DEFINES += IRQMEDIA_LIBRARY

include(../libs.pri)

SOURCES += \
    irqMedia.cpp

HEADERS += \
    irqMedia_global.h \
    irqMedia.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
