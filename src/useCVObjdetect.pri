# {circ-code}/src/useBase.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/QtCVObjdetect
INCLUDEPATH *= $$LIBDIR/../../src/libs/QtCVObjdetect
windows:LIBS *= -lQtCVObjdetect6
linux:LIBS *= -lQtCVObjdetect
LIBS *= -L$$DESTDIR

HEADERS +=


