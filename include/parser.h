#pragma once
#include "expression.h"
#include "lexer.h"
#include <cmath>
#include <memory>
#include <variant>

class Parser {

private:
  std::vector<Token> _tokens;
  int currentIndex = 0;

public:
  Parser(std::vector<Token> &token) : _tokens(token) {};
  bool check(TokenType type);
  void advance();
  bool isAtEnd();
  Token previous();
  Token consume(TokenType type, std::string message);
  Token peek();
  bool match(const std::vector<Token> &tokens);
  ExprPtr parse();
  ExprPtr statement();
  ExprPtr expression();

  ExprPtr equality();
  ExprPtr comparison();
  ExprPtr term();
  ExprPtr factor();
  ExprPtr unary();
  ExprPtr primary();
};
