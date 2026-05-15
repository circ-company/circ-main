QT += gui
TEMPLATE = lib
DEFINES += IRQGUI_LIBRARY

include(../libs.pri)

SOURCES += \
    irqGui.cpp

HEADERS += \
    irqGui_global.h \
    irqGui.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
