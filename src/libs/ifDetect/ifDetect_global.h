#pragma once

#include <QtCore/qglobal.h>

#if defined(IFDETECT_LIBRARY)
#define IFDETECT_EXPORT Q_DECL_EXPORT
#else
#define IFDETECT_EXPORT Q_DECL_IMPORT
#endif
