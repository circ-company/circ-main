QT -= gui
QT *= network
TEMPLATE = lib
DEFINES += IRQNETWORK_LIBRARY

include(../libs.pri)
include(../../useBase.pri)

SOURCES += \
    NetworkMacAddress.cpp \
    Url.cpp \
    UrlType.cpp \
    irqNetwork.cpp

HEADERS += \
    NetworkMacAddress.h \
    Url.h \
    UrlType.h \
    irqNetwork_global.h \
    irqNetwork.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../useQNetwork.pri
