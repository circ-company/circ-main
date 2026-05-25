QT -= gui
TEMPLATE = lib
DEFINES += IREXE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useTypes.pri)
include(../../useQWidgets.pri)

SOURCES += \
    ObjectHelper.cpp \
    irExe.cpp

HEADERS += \
    ObjectHelper.h \
    irExe_global.h \
    irExe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
