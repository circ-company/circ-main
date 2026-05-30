QT *= gui
TEMPLATE = lib
DEFINES += IRQCORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
#include(../../useTypes.pri)
#include(../../useCore.pri)

SOURCES += \
    QQCoreApplication.cpp \
    irqCore.cpp

HEADERS += \
    QQCoreApplication.h \
    irqCore_global.h \
    irqCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
