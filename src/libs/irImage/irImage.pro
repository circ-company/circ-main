QT += gui \
    widgets
TEMPLATE = lib
DEFINES += IRIMAGE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)

SOURCES += \
    Image.cpp \
    ImageGallery.cpp \
    MainWindowImageGallery.cpp \
    irImage.cpp

HEADERS += \
    Image.h \
    ImageGallery.h \
    MainWindowImageGallery.h \
    irImage_global.h \
    irImage.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
