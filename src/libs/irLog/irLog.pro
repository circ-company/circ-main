QT -= gui
TEMPLATE = lib
DEFINES += IRLOG_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useTypes.pri)

SOURCES += \
    Log.cpp \
    LogEngine.cpp \
    LogItem.cpp \
    LogMsgType.cpp \
    irLog.cpp

HEADERS += \
    Log.h \
    LogEngine.h \
    LogItem.h \
    LogMacros.h \
    LogMsgType.h \
    irLog_global.h \
    irLog.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
