#pragma once

#include <QtCore/qglobal.h>

#if defined(IRIMAGE_LIBRARY)
#define IRIMAGE_EXPORT Q_DECL_EXPORT
#else
#define IRIMAGE_EXPORT Q_DECL_IMPORT
#endif
