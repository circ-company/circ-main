#include "ryCamera.h"

ryCamera::ryCamera(QObject *parent)
    : QObject{parent}
{
    setObjectName("ryCamera:null");

}
/*
ryCamera::ryCamera(const ryCameraConfig &aConfig, QObject *parent)
    : QObject{parent}
{
    QUrl tUrl = aConfig.url();
    setObjectName("ryCamera:null");

}
*/

