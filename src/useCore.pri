# {irMain}/useCore.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irCore
#NCLUDEPATH *= $$LIBDIR/../../src/libs/irCore
windows:LIBS *= -lirCore6
linux:LIBS *= -lirCore
LIBS *= -L$$DESTDIR
#message(--------/src/useCore.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


