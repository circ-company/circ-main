# {circ-main}/src/srcLD.pri
#message(^^^^^^^^/src/srcLD.pri)

include(DESTDIR.pri)
CONFIG += c++23
INCLUDEPATH *= .. . $$LIBDIR/..
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
QMAKE_CXXFLAGS *= -Werror=return-type

DEFINES_DEBUG *= __CIRC__WARN_IS_ERROR
DEFINES_DEBUG *= __CIRC__ERROR_IS_FAULT

message(DESTDIR = $$DESTDIR)

