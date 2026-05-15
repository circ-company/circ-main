# {irMain}/useQCore.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irqCore
INCLUDEPATH *= $$LIBDIR/../../irMain/libs/irqCore
windows:LIBS *= -lirqCore6
linux:LIBS *= -lirqCore
LIBS *= -L$$DESTDIR
#message(--------/src/useCore.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


