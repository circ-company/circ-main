#pragma once

#include <QApplication>


#include <FileInfo.h>
#include <List.h>
#include <Types.h>
#include <UText.h>
#include <UTextList.h>

class QQMainWindow;

class QQApplication : public QApplication
{
    Q_OBJECT
protected:
    QQApplication(int &argc, char **argv);

public slots:
    virtual void run();
    virtual void initialize();
    virtual void start();
    virtual void processFile(const FileInfo fi);

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
    QQApplication * it() { return this; }

protected: // pointers
public: // pointers

private:
    FileInfo mExeInfo;
    UTextList mArguments;
    QQMainWindow * mpMainWindow=nullptr;

};

inline QFileInfo QQApplication::exeInfo() const { return mExeInfo; }
inline Count QQApplication::argCount() const { return argList().count(); }
inline bool QQApplication::isValidArgIndex(const Index ix) const { return argList().isValidIndex(ix); }
inline UTextList QQApplication::argList() const { return mArguments; }
inline UText QQApplication::argAt(const Index ix) const { return argList().value(ix); }
inline UText QQApplication::takeArgAt(const Index ix) { return argList().takeAt(ix); }
