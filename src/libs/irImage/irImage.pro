QT += gui
TEMPLATE = lib
DEFINES += IRIMAGE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)

SOURCES += \
    Image.cpp \
    irImage.cpp

HEADERS += \
    Image.h \
    irImage_global.h \
    irImage.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
