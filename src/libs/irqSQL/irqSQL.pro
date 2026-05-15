QT -= gui
TEMPLATE = lib
DEFINES += IRQSQL_LIBRARY

include(../libs.pri)

SOURCES += \
    irqSQL.cpp

HEADERS += \
    irqSQL_global.h \
    irqSQL.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
