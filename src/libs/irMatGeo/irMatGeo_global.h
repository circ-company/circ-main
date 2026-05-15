#pragma once

#include <QtCore/qglobal.h>

#if defined(IRMATGEO_LIBRARY)
#define IRMATGEO_EXPORT Q_DECL_EXPORT
#else
#define IRMATGEO_EXPORT Q_DECL_IMPORT
#endif
