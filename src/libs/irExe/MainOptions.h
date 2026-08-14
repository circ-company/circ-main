#pragma once

#include <QCommandLineParser>
class QCommandLineOption;

#include <AText.h>
#include <CText.h>
#include <KeyMap.h>
#include <KeySegList.h>
#include <KeySegMap.h>

class MainOptions
{
public: // types
    enum ShowOption { $null, Minimize, Maximize, Normal };

public: // ctors
    MainOptions();

public: // const
    ShowOption option() const;
    ATextList arguments() const;
    KeyTextMap settings() const;
    KeySegList positionalNames() const;
    AText positional(const KeySeg &aName) const;

public: // non-const
    void applicationDescription(const QString &aDesc);
    void addPositional(const KeySeg &aName, const AText &aDesc);
    void positionalSyntax(const KeySeg &aName, const AText &aSyntax);
    void process(const QCoreApplication &aApp);

public: // pointers
    QCommandLineParser * parser();

private:
    ShowOption mShowOption=$null;
    QCommandLineParser mParser;
    ATextList mArguments;
    KeyTextMap mSettingMap;
    KeySegList mPositonalNames;
    KeySegMapT<AText> mPosDescMap;
    KeySegMapT<AText> mPosSyntaxMap;
    KeySegMapT<AText> mPosValuesMap;
    QCoreApplication * mpCoreApplication=nullptr;
    QCommandLineOption * mpHelpCLO=nullptr;
    QCommandLineOption * mpVersionCLO=nullptr;
    QCommandLineOption * mpMinimizeCLO=nullptr;
    QCommandLineOption * mpMaximizeCLO=nullptr;
    QCommandLineOption * mpNormalCLO=nullptr;
};

inline ATextList MainOptions::arguments() const { return mArguments; }
inline KeyTextMap MainOptions::settings() const { return mSettingMap; }
inline KeySegList MainOptions::positionalNames() const { return mPositonalNames; }
inline QCommandLineParser *MainOptions::parser() { return &mParser; }
inline MainOptions::ShowOption MainOptions::option() const { return mShowOption; }
