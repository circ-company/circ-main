QT += widgets
TEMPLATE = lib
DEFINES += RYWIDGETS_LIBRARY

include(../libs.pri)
include(../../useQWidgets.pri)

SOURCES += \
    BaseRYScreen.cpp \
    FaceWidget.cpp \
    ryWidgets.cpp

HEADERS += \
    BaseRYScreen.h \
    FaceWidget.h \
    ryWidgets_global.h \
    ryWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
