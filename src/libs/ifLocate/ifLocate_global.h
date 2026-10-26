#pragma once

#include <QtCore/qglobal.h>

#if defined(IFLOCATE_LIBRARY)
#define IFLOCATE_EXPORT Q_DECL_EXPORT
#else
#define IFLOCATE_EXPORT Q_DECL_IMPORT
#endif
