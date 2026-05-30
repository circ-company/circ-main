# {ottoZcode}/src/useStore.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irStore
INCLUDEPATH *= $$LIBDIR/../../src/libs/irStore
windows:LIBS *= -lirStore6
linux:LIBS *= -lirStore
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


