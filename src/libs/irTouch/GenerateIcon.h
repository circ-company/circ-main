#pragma once

#include <QWidget>

#include <Size.h>
#include <UText.h>

#include "GenerateIconScheme.h"

class GenerateIcon : public QWidget
{
    Q_OBJECT
public: // types

public: // ctors
    explicit GenerateIcon(QWidget *parent=nullptr);
    GenerateIcon(const Size aSize, QWidget *parent=nullptr);
    GenerateIcon(const GenerateIconScheme aScheme,
                 QWidget *parent=nullptr);
    GenerateIcon(const Size aSize,
                 const GenerateIconScheme aScheme,
                 QWidget *parent=nullptr);

public slots:
    void set(const Size aSize);
    void set(const GenerateIconScheme aScheme);
    void generate(const Size aSize,
                  const UText &aText);
    void generate(const GenerateIconScheme &aScheme,
                  const UText &aText);
    void generate(const Size aSize,
                  const GenerateIconScheme &aScheme,
                  const UText &aText);
    void generate(const UText &aText);

signals:
    void sizeSet(const Size aSize);
    void schemeSet(const GenerateIconScheme aScheme);
    void generated(const QIcon aIcon);

public: // const

public: // non-const

private:
    QPixmap makeNormalOn(const UText &aText);
    QPixmap makeDisableOn(const UText &aText);
    QPixmap makeActiveOn(const UText &aText);
    QPixmap makeSelectOn(const UText &aText);
    QPixmap makeNormalOff(const UText &aText);
    QPixmap makeDisableOff(const UText &aText);
    QPixmap makeActiveOff(const UText &aText);
    QPixmap makeSelectOff(const UText &aText);
    QPixmap draw(const UText &aText, const GenerateIconScheme &aScheme);

    // ----------------------- properties ----------------------
private:
    Size mSize;
    GenerateIconScheme mScheme;
    QIcon mIcon;
    Q_PROPERTY(Size mSize READ size WRITE size NOTIFY sizeSet FINAL);
    Q_PROPERTY(GenerateIconScheme mScheme READ scheme WRITE scheme NOTIFY schemeSet FINAL);
    Q_PROPERTY(QIcon mIcon READ icon WRITE icon NOTIFY generated FINAL);

public:
    Size size() const { return mSize; }
    GenerateIconScheme scheme() const { return mScheme; }
    QIcon icon() const { return mIcon; }
    void size(const Size aSize) { mSize = aSize; }
    void scheme(const GenerateIconScheme aScheme) { mScheme = aScheme; }
    void icon(const QIcon aIcon) { mIcon = aIcon; }
};

