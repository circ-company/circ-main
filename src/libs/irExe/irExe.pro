QT *= gui
TEMPLATE = lib
DEFINES += IREXE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
#include(../../useTypes.pri)
#include(../../useQWidgets.pri)

SOURCES += \
    Action.cpp \
    ActionManager.cpp \
    CommandLine.cpp \
    ExeObject.cpp \
    ObjectHelper.cpp \
    Settings.cpp \
    irExe.cpp

HEADERS += \
    Action.h \
    ActionManager.h \
    CommandLine.h \
    ExeObject.h \
    ObjectHelper.h \
    Settings.h \
    irExe_global.h \
    irExe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
