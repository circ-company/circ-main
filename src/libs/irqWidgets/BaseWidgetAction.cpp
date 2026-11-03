#include "BaseWidgetAction.h"

BaseWidgetAction::BaseWidgetAction(QObject *parent)
    : QWidgetAction(parent)
{
    setObjectName("WidgetAction");
}

