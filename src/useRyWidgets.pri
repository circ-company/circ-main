# {circ-code}/src/useRyWidgets.pri



INCLUDEPATH *= $$LIBDIR/ryWidgets
#NCLUDEPATH *= $$LIBDIR/../../src/libs/ryWidgets
windows:LIBS *= -lryWidgets6
linux:LIBS *= -lryWidgets
LIBS *= -L$$DESTDIR
#message(--------/src/useBase.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=


