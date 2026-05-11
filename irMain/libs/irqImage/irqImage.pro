QT += gui
TEMPLATE = lib
DEFINES += IRQIMAGE_LIBRARY

include(../libs.pri)

SOURCES += \
    irqImage.cpp

HEADERS += \
    irqImage_global.h \
    irqImage.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
