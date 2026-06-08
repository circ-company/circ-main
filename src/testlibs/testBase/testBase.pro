QT += testlib
QT -= gui
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
TEMPLATE = app

include(../testlibs.pri)
include(../../useBase.pri)

SOURCES +=  tst_testbase.cpp
