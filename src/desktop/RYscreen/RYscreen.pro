QT *= core
QT *= gui
QT *= widgets

include(../desktop.pri)

SOURCES += \
    RYApplication.cpp \
    main.cpp \
    RYMainWindow.cpp \

HEADERS += \
    RYApplication.h \
    RYMainWindow.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$DESTDIR -lirBase -lirLog -lirMatGeo -lryWidgets -lirqWidgets

message(===RYscreen.pro: DESTDIR=$$DESTDIR LIBS=$$LIBS)

