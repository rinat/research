// Scanner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Scanner.h"

int _tmain(int argc, _TCHAR* argv[])
{
    using namespace analysis;

    std::string source("id = a + b");
    Scanner scanner;
    scanner.Init(source);

    for (auto token = scanner.Next(); token != Token::Eos; token = scanner.Next())
    {
        std::cout << Token::TokenToString(token) << "\n";
    }
    std::cout << std::endl;

    return 0;
}