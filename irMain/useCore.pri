# {ottoZcode}/src/useCore.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irCore
INCLUDEPATH *= $$LIBDIR/../../irMain/libs/eirCore
windows:LIBS *= -leirCore7
linux:LIBS *= -leirCore
LIBS *= -L$$DESTDIR
#message(--------/src/useCore.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


