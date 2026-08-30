#include "../include/parser.h"

SyntaxTree Parser::parse(const std::vector<Token>& tokens) {

    int position = 0;
    int start = 0;

    while(position < tokens.size()) {

        auto token = tokens[position++];

        switch(token.getToken()) {
            case TokenType::LEFT_PAREN:
                // process groupoing
                // create output group 
                // which is an element containing a number of 
                break; 
            case TokenType::INT:
            case TokenType::DOUBLE:
            case TokenType::CHAR:
            case TokenType::LONG:
            case TokenType::LONGLONG:
                // process declaration
                break;
            case TokenType::IDENTIFIER:
                // process Expression
                // or statement 
                break; 
            case TokenType::IF:
                // process IfStatement 
                break; 
            default:
                // do nothing
        }
    }
    
}