#pragma once

#include <MainWindowImageGallery.h>

class ATApplication;

class ATMainWindow : public MainWindowImageGallery
{
    Q_OBJECT

public:
    explicit ATMainWindow(ATApplication *pApp);
    ~ATMainWindow() override;

private:
    ATApplication * mpApplication=nullptr;
};
