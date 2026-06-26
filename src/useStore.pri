# {circ-main}/src/useStore.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irStore
INCLUDEPATH *= $$LIBDIR/../../src/libs/irStore
windows:LIBS *= -lirStore6
linux:LIBS *= -lirStore
LIBS *= -L$$DESTDIR

HEADERS +=


