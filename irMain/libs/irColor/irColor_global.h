#pragma once

#include <QtCore/qglobal.h>

#if defined(IRCOLOR_LIBRARY)
#define IRCOLOR_EXPORT Q_DECL_EXPORT
#else
#define IRCOLOR_EXPORT Q_DECL_IMPORT
#endif
