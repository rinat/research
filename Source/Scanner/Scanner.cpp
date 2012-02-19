#include "stdafx.h"

#include "Scanner.h"

namespace analysis
{

Scanner::Scanner()
    : _sourcePosition(0)
{}

void Scanner::Init(const std::string& source)
{
    _source = source;
    _sourcePosition = 0;
    _nextToken = Scan();
}

Token::Kind Scanner::Next()
{
    Token::Kind curToken = _nextToken;

    bool cycle = true;
    do 
    {
        _nextToken = Scan();
        if (_nextToken != Token::Illegal)
        {
            break;
        }
    } while (cycle);

    return curToken;
}

Token::Kind Scanner::Peek()
{
    return _nextToken;
}

Token::Kind Scanner::Scan()
{
    SkipWhiteSpaces();

    char ch = ReadChar();
    switch (ch)
    {
    case 0:
        return Token::Eos;

    case '=':
        return Token::Assign;

    case '+':
        return Token::Add;

    default:
        if (IsIdentifierBegin(ch))
        {
            return ReadIdentifier(ch);
        }
    }
    return Token::Illegal;
}

Token::Kind Scanner::ReadIdentifier(char ch)
{
    assert(IsIdentifierBegin(ch));
    for (; IsIdentifierPart(ch = PeekChar()); ReadChar())
    {}

    return Token::Id;
}

bool Scanner::IsIdentifierBegin(char ch)
{
    return (ch == '_' || isalpha(ch));
}

bool Scanner::IsIdentifierPart(char ch)
{
    return (IsIdentifierBegin(ch) || isdigit(ch));
}

void Scanner::SkipWhiteSpaces()
{
    char ch = PeekChar();
    while (isspace(ch))
    {
        ReadChar();
        ch = PeekChar();
    }
}

char Scanner::PeekChar()
{
    return (_sourcePosition != static_cast<size_t>(_source.length()))
        ? _source[_sourcePosition]
        : 0;
}

char Scanner::ReadChar()
{
    char ch = PeekChar();
    if (ch != 0)
    {
        ++_sourcePosition;
    }

    return ch;
}

}