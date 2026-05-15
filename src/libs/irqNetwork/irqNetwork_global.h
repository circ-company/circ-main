#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQNETWORK_LIBRARY)
#define IRQNETWORK_EXPORT Q_DECL_EXPORT
#else
#define IRQNETWORK_EXPORT Q_DECL_IMPORT
#endif
