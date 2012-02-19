#pragma once

namespace analysis
{

class Token
{
public:
    enum Kind
    {
        Illegal = -1,
        Id,
        Assign,
        Add,
        Eos
    };

    static std::string TokenToString(Token::Kind token);
};

}