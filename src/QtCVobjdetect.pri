# {ottoZcode}/src/useQtCVobjdetect.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/QtCVobjdetect
INCLUDEPATH *= $$LIBDIR/../../src/libs/QtCVobjdetect
windows:LIBS *= -lQtCVobjdetect6
linux:LIBS *= -lQtCVobjdetect
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


