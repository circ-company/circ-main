#pragma once

#include <QObject>

#include <QMap>

#include <DualMap.h>
#include <EightCC.h>
#include <SCRect.h>
#include <Size.h>
#include <UText.h>

class LoyaltyDisplayScreen;
class ToolButton;

class ToolButtonGenerator : public QObject
{
public: // ctors
    ToolButtonGenerator(LoyaltyDisplayScreen *parent=nullptr);

public slots:
    void initialize();
    void setup();
    void run();
    void clear();

signals:
    void initialized();
    void setupd();
    void running();

public: // const
    const Size buttonSize() const;
    const Size layoutSize() const;
    Count buttonCount() const;
    EightCC ecc(const Index aIx) const;
    Index galleryIndex(const EightCC aECC) const;
    Point galleryPoint(const EightCC aECC) const;
    Point galleryPoint(const Index aIX) const;
    UText name(const EightCC aECC) const;
    UText colorName(const EightCC aECC) const;

public: // non-const
    ToolButton * button(const EightCC aECC);

public: // pointer
    LoyaltyDisplayScreen * screen();

private: // non-const
    void initEccIndexDMap();
    void initButtonNames();
    void initColorNames();

private:
    LoyaltyDisplayScreen * mpScreen=nullptr;
    const Size cmButtonSize;
    const Size cmLayoutSize;
    DualMap<EightCC, Index> mEccIndexDMap;
    QMap<EightCC, UText> mEccButtonNameMap;
    QMap<EightCC, UText> mEccColorNameMap;
    QMap<EightCC, ToolButton *> mEccButtonMap;
};

inline const Size ToolButtonGenerator::buttonSize() const { return cmButtonSize; }
inline const Size ToolButtonGenerator::layoutSize() const { return cmLayoutSize; }
inline Count ToolButtonGenerator::buttonCount() const { return layoutSize().area(); }
