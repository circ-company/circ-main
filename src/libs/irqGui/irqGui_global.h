#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQGUI_LIBRARY)
#define IRQGUI_EXPORT Q_DECL_EXPORT
#else
#define IRQGUI_EXPORT Q_DECL_IMPORT
#endif
