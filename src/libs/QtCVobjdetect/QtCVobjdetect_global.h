#pragma once

#include <QtCore/qglobal.h>

#if defined(QTCVOBJDETECT_LIBRARY)
#define QTCVOBJDETECT_EXPORT Q_DECL_EXPORT
#else
#define QTCVOBJDETECT_EXPORT Q_DECL_IMPORT
#endif
