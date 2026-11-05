QT += widgets
TEMPLATE = lib
DEFINES += RYWIDGETS_LIBRARY

include(../libs.pri)
include(../../useLog.pri)
include(../../useTypes.pri)
include(../../useCore.pri)
include(../../useColor.pri)
include(../../useQWidgets.pri)

SOURCES += \
    BaseRYScreen.cpp \
    FaceWidget.cpp \
    ryCamera.cpp \
    ryCameraConfig.cpp \
    ryFaceGrid.cpp \
    ryStatusBar.cpp \
    ryTaskBar.cpp \
    ryTaskButton.cpp \
    ryWidgets.cpp

HEADERS += \
    BaseRYScreen.h \
    FaceWidget.h \
    ryCamera.h \
    ryCameraConfig.h \
    ryFaceGrid.h \
    ryStatusBar.h \
    ryTaskBar.h \
    ryTaskButton.h \
    ryWidgets_global.h \
    ryWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
