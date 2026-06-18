QT += gui
TEMPLATE = lib
DEFINES += QTCVUTILS_LIBRARY

include(../libs.pri)

SOURCES += \
    QtCVutils.cpp \
    Rect.cpp    \

HEADERS += \
    QtCVutils_global.h \
    QtCVutils.h \
    Rect.h  \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
