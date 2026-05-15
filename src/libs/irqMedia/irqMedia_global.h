#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQMEDIA_LIBRARY)
#define IRQMEDIA_EXPORT Q_DECL_EXPORT
#else
#define IRQMEDIA_EXPORT Q_DECL_IMPORT
#endif
