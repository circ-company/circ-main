QT += widgets
TEMPLATE = lib
DEFINES += IRQWIDGETS_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)
include(../../useTypes.pri)

SOURCES += \
    Application.cpp \
    BaseWidgetAction.cpp \
    Label.cpp \
    LabelMap.cpp \
    MainWindow.cpp \
    QQTextDocument.cpp \
    QQTextEdit.cpp \
    ToolBar.cpp \
    ToolButton.cpp \
    irqWidgets.cpp

HEADERS += \
    Application.h \
    BaseWidgetAction.h \
    Label.h \
    LabelMap.h \
    MainWindow.h \
    QQTextDocument.h \
    QQTextEdit.h \
    ToolBar.h \
    ToolButton.h \
    irqWidgets_global.h \
    irqWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
