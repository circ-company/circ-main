#pragma once

#include <QObject>

#include "AText.h"
#include "Id.h"
#include "TokenList.h"

class Tokenizer : public QObject
{
    Q_OBJECT
public:
public:
    explicit Tokenizer(const Id &id, QObject *parent = nullptr);

public slots:
    void clear();
    void append(const AText &in);
    void process();

signals:
    void cleared();
    void processing(const AText &in);
    void added(const Token::Pair &tok);
    void processed(const TokenList &toks);

public:

public:

public: // static
    static TokenList process(const AText &in);

private:
    const Id cmId;
    AText mInputText;
    TokenList mOutputTokens;
};
