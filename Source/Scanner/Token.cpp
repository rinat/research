#include "stdafx.h"

#include "Token.h"

namespace analysis
{

std::string Token::TokenToString(Token::Kind token)
{
    switch (token)
    {
    case Token::Add: return std::string("+");
    case Token::Assign: return std::string("=");
    case Token::Eos: return std::string("end of program");
    case Token::Id: return std::string("identifier");
    case Token::Illegal: return std::string("illegal");
    default: return std::string();
    }
}

}