# {circ-main}/src/useQtCVod.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/QtCVobjdetect
#NCLUDEPATH *= $$LIBDIR/../../src/libs/QtCVobjdetect
windows:LIBS *= -lQtCVobjdetect6
linux:LIBS *= -lQtCVobjdetect
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


