#pragma once

#include <QtCore/qglobal.h>

#if defined(BOOSTLOGGING_LIBRARY)
#define BOOSTLOGGING_EXPORT Q_DECL_EXPORT
#else
#define BOOSTLOGGING_EXPORT Q_DECL_IMPORT
#endif
