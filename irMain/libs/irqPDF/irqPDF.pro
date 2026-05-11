QT += gui
TEMPLATE = lib
DEFINES += IRQPDF_LIBRARY

include(../libs.pri)

SOURCES += \
    irqPDF.cpp

HEADERS += \
    irqPDF_global.h \
    irqPDF.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
