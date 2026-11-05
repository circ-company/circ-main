#pragma once

#include <QObject>
#include <Application.h>

#include <QFileInfo>
#include <QJsonDocument>
#include <QStringList>

class RYApplication : public Application
{
    Q_OBJECT
public:
    RYApplication(int argc, char *argv[]);

public slots:
//    void run();
  //  void initialize();
    //void setup();
    //void ready();

signals:
    void running();
    void initialized();
    void setuped();
    void readied();


public: // const
//    const QJsonDocument jsonDocument() const;

private:
    QStringList mArguments;
  //  QFileInfo mJsonFI;
    //QJsonDocument mJsonDoc;
};
