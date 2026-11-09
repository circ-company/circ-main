#pragma once

#include <Application.h>

#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
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
    void setup();
    //void ready();
    void start();
    void processFile();
    void finish();

signals:
    void finished();

public: // const

public: // non-const

public: // pointers


private:
    QDir mInputDir;
    QFileInfoList mFIList;
  //  QFileInfo mJsonFI;
    //QJsonDocument mJsonDoc;
};
