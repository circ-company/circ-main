#pragma once

#include <QApplication>

#include <QList>

#include <FileInfo.h>
#include <Types.h>
#include <UText.h>
#include <UTextList.h>

class MainWindow;

class Application : public QApplication
{
    Q_OBJECT
protected:
    Application(int &argc, char **argv);

public slots:
    virtual void run();
    virtual void initialize();
    virtual void setup();
    virtual void start();
    virtual void processFile();

signals:
    void running();
    void initialized();
    void started();
    void processedFile(const FileInfo fi);

public: // const
    Count argCount() const;
    bool isValidArgIndex(const Index ix) const;
    UTextList argList() const;
    UText argAt(const Index ix) const;
    QFileInfo exeInfo() const;

public: // non-const
    UText takeArgAt(const Index ix);

public: // pointers
    Application * it() { return this; }

protected: // pointers
public: // pointers

private:
    FileInfo mExeInfo;
    UTextList mArguments;
    MainWindow * mpMainWindow=nullptr;

};

inline QFileInfo Application::exeInfo() const { return mExeInfo; }
inline Count Application::argCount() const { return argList().count(); }
inline bool Application::isValidArgIndex(const Index ix) const { return argList().isValidIndex(ix); }
inline UTextList Application::argList() const { return mArguments; }
inline UText Application::argAt(const Index ix) const { return argList().value(ix); }
inline UText Application::takeArgAt(const Index ix) { return argList().takeAt(ix); }
