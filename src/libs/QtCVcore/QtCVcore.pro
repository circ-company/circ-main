# {QtCV}/QtCVcore.pro

QT += gui
TEMPLATE = lib
DEFINES += QTCVCORE_LIBRARY

include(../libs.pri)

SOURCES += \
    QtCVcore.cpp \
    cvqPoint.cpp \
    cvqSize.cpp \
    qcvPoint.cpp \
    qcvSize.cpp \

HEADERS += \
    QtCVcore_global.h \
    QtCVcore.h \
    cvqPoint.h \
    cvqSize.h \
    qcvPoint.h \
    qcvSize.h   \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/ -lopencv_core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/ -lopencv_cored
else:unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/ -lopencv_core

INCLUDEPATH += $$PWD/../../../../../../../usr/include/opencv4
DEPENDPATH += $$PWD/../../../../../../../usr/include/opencv4
