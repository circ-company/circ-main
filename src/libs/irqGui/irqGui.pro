QT += gui
TEMPLATE = lib
DEFINES += IRQGUI_LIBRARY

include(../libs.pri)
include(../../useTypes.pri)

SOURCES += \
    QQGuiApplication.cpp \
    irqGui.cpp

HEADERS += \
    QQGuiApplication.h \
    irqGui_global.h \
    irqGui.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
