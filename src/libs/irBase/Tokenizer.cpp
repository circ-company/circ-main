#include "Tokenizer.h"

Tokenizer::Tokenizer(const Id &id, QObject *parent)
    : QObject{parent}
    , cmId(id)
{
    setObjectName("Tokenizer:" + cmId.toString());
}

void Tokenizer::clear()
{

}

void Tokenizer::append(const AText &in)
{

}

void Tokenizer::process()
{

}

