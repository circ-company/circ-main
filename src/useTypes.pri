# {circ-main}/src/useTypes.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irTypes
windows:LIBS *= -lirTypes6
linux:LIBS *= -lirTypes
LIBS *= -L$$DESTDIR
