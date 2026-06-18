# {circ-code}/src/useCVobjdetect.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/QtCVobjdetect
INCLUDEPATH *= $$LIBDIR/../../src/libs/QtCVobjdetect
windows:LIBS *= -lQtCVobjdetect6
linux:LIBS *= -lQtCVobjdetect
LIBS *= -L$$DESTDIR


