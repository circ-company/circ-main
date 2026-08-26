#pragma once

#include <QtCore/qglobal.h>

#if defined(IRTOUCH_LIBRARY)
#define IRTOUCH_EXPORT Q_DECL_EXPORT
#else
#define IRTOUCH_EXPORT Q_DECL_IMPORT
#endif
