QT -= gui
TEMPLATE = lib
DEFINES += IRLOG_LIBRARY
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../libs.pri)
include(../../useBase.pri)
include(../../useTypes.pri)

SOURCES += \
    LogEngine.cpp \
    LogItem.cpp \
    irLog.cpp

HEADERS += \
    LogEngine.h \
    LogItem.h \
    irLog_global.h \
    irLog.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
