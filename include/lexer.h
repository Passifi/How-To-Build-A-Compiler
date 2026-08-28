#pragma once
#include "NewToken.h"
#include "macros.h"
#include "token.h"
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <variant>



class Lexer {
public:
  int start;
  int current;
  int line;
  std::vector<Token> lexems;
  std::string data;
  Lexer(std::string &data);
  std::vector<Token> getLexems();

private:
  bool isValidIdentifiter(char c);
  bool isAtEnd();
  char advance();
  void number();
  void identifier();
  bool match(char expected);
  char peek();
  char peekNext();
  void string();
  void addToken(TokenType type, std::string lexeme);
};
