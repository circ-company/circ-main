#include "ryCameraConfig.h"

#include <utility>


class ryCameraConfigData : public QSharedData
{
public:
    QUrl            dUrl;
    quint64         dSampleMsec;
};

QUrl ryCameraConfig::url() const
{
    Q_CHECK_PTR(data);
    return data->dUrl;
}

quint64 ryCameraConfig::sampleMsec() const
{
    Q_CHECK_PTR(data);
    return data->dSampleMsec;
}

ryCameraConfig::ryCameraConfig()
    : data(new ryCameraConfigData)
{}

ryCameraConfig::ryCameraConfig(const ryCameraConfig &rhs)
    : data{rhs.data}
{}

ryCameraConfig::ryCameraConfig(ryCameraConfig &&rhs)
    : data{std::move(rhs.data)}
{}

ryCameraConfig &ryCameraConfig::operator=(const ryCameraConfig &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

ryCameraConfig &ryCameraConfig::operator=(ryCameraConfig &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

ryCameraConfig::~ryCameraConfig() {}
