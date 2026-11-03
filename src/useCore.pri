# {circ-main}/src/useCore.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irCore
windows:LIBS *= -lirCore6
linux:LIBS *= -lirCore
LIBS *= -L$$DESTDIR

HEADERS +=


