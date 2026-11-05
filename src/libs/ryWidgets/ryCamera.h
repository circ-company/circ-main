#pragma once

#include <QObject>


#include "ryCameraConfig.h"

class ryCamera : public QObject
{
    Q_OBJECT
public:
    explicit ryCamera(QObject *parent = nullptr);
//    ryCamera(const QJsonDocument &aConfig, QObject *parent = nullptr);


public slots:
//    void configure(const QJsonDocument &aConfig);
  //  void initialize();
    //void setup();
    //void ready();

signals:
    void configurated();
    void initialized();
    void setuped();
    void readied();


public: // const
//    bool isConfigured() const;
  //  const ryCameraConfig configuration() const;

private:
    //ryCameraConfig mConfiguration;
};

//inline bool ryCamera::isConfigured() const { return ! configuration().isEmpty(); }
