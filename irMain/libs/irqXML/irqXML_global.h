#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQXML_LIBRARY)
#define IRQXML_EXPORT Q_DECL_EXPORT
#else
#define IRQXML_EXPORT Q_DECL_IMPORT
#endif
