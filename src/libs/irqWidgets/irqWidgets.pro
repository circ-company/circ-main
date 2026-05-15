QT += widgets
TEMPLATE = lib
DEFINES += IRQWIDGETS_LIBRARY

include(../libs.pri)

SOURCES += \
    irqWidgets.cpp

HEADERS += \
    irqWidgets_global.h \
    irqWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
