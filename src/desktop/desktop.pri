# {circ-main}/src/desktop/desktop.pri
#message(____________/desktop/desktop.pri)

include(../LIBDIR.pri)
CONFIG(release, debug|release):DEFINES *= __CIRC__WARN_IS_ERROR
CONFIG(debug,   debug|release):DEFINES *= __CIRC__WARN_IS_FAULT

include(../src.pri)
