# {ottoZcode}/src/useTypes.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irTypes
INCLUDEPATH *= $$LIBDIR/../../src/libs/irBase
INCLUDEPATH *= $$LIBDIR/../../src/libs/irTypes
windows:LIBS *= -lirTypes6
linux:LIBS *= -lirTypes
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


