#pragma once

#include <QMainWindow>

//#include <QFileDialog>
#include <QMdiArea>
//#include <QStackedLayout>
//#include <QWidget>
class QMenuBar;

#include <FileInfo.h>
#include <FileInfoList.h>
#include <Image.h>
#include <Key.h>
#include <Label.h>
#include <LabelMap.h>
#include <Log.h>

class irViewApplication;

class irViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    irViewMainWindow(irViewApplication * pApp);
    ~irViewMainWindow();

public slots:
    void run();
    void initialize();
    void setup();
    void start();
    void doFileOpenDialog();
    void viewImage(const Key aKey, const Image aImage);

signals:
    void running();
    void initialized();
    void setuped();
    void started();
    void imageOpenDialogFile(const FileInfo &aImageFI);
    void opened(const FileInfo &aImageFI, const bool aSuccess);

public: // non-const

public: // pointers
    irViewApplication * app();

private:
    void setupMenus();

private:
    irViewApplication * mpApplication=nullptr;
    QMenuBar * mpMenuBar=nullptr;
    bool mMdiMode=false;
    QMdiArea * mpMdiArea=nullptr;
    Label * mpMainLabel=nullptr;
    KeyList mSortOrderKeys;
    LabelMap mLabelMap;
};

inline irViewApplication *irViewMainWindow::app() { CKPOINTER(mpApplication); return mpApplication; }
