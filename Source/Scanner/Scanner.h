#pragma once

#include "Token.h"

namespace analysis
{

class Scanner
{
public:
    Scanner();

    void Init(const std::string& source);

    Token::Kind Next();
    Token::Kind Peek();

private:
    Token::Kind Scan();
    void SkipWhiteSpaces();
    
    char PeekChar();
    char ReadChar();

    Token::Kind ReadIdentifier(char ch);
    bool IsIdentifierBegin(char ch);
    bool IsIdentifierPart(char ch);

private:
    Token::Kind _nextToken;
    size_t _sourcePosition;
    std::string _source;

private:
    Scanner(const Scanner&);
    void operator =(const Scanner&);
};

}