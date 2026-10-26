#pragma once

#include <QtCore/qglobal.h>

#if defined(IFGENERATE_LIBRARY)
#define IFGENERATE_EXPORT Q_DECL_EXPORT
#else
#define IFGENERATE_EXPORT Q_DECL_IMPORT
#endif
