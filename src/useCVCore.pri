# {circ-code}/src/useBase.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/QtCVcore
INCLUDEPATH *= $$LIBDIR/../../src/libs/QtCVcore
windows:LIBS *= -lQtCVcore6
linux:LIBS *= -lQtCVcore
LIBS *= -L$$DESTDIR

HEADERS +=


