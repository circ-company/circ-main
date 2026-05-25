# {ottoZcode}/src/useImage.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irImage
INCLUDEPATH *= $$LIBDIR/../../src/libs/irImage
windows:LIBS *= -lirImage6
linux:LIBS *= -lirImage
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


