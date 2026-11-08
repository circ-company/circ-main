#pragma once

#include <Application.h>

#include <QFileInfo>
#include <QList>
#include <QJsonDocument>
#include <QStringList>
class QAction;

#include "ryTaskBar.h"

class RYApplication : public Application
{
    Q_OBJECT
public:
    RYApplication(int argc, char *argv[]);

public slots:
//    void run();
    void initialize();
    //void setup();
    //void ready();
/*
signals:
    void running();
    void initialized();
    void setuped();
    void readied();
*/

public: // const
//    const QJsonDocument jsonDocument() const;

public: // non-const

public: // pointers


private:
  //  QFileInfo mJsonFI;
    //QJsonDocument mJsonDoc;
};
