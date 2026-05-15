QT += gui
TEMPLATE = lib
DEFINES += IRIMAGE_LIBRARY

include(../libs.pri)

SOURCES += \
    irImage.cpp

HEADERS += \
    irImage_global.h \
    irImage.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
