#pragma once

#include <QSharedDataPointer>

#include <QUrl>

class ryCameraConfigData;

class ryCameraConfig
{

public:
    QUrl url() const;
    quint64 sampleMsec() const;

public:
    ryCameraConfig();
    ryCameraConfig(const ryCameraConfig &);
    ryCameraConfig(ryCameraConfig &&);
    ryCameraConfig &operator=(const ryCameraConfig &);
    ryCameraConfig &operator=(ryCameraConfig &&);
    ~ryCameraConfig();

private:
    QSharedDataPointer<ryCameraConfigData> data;
};
