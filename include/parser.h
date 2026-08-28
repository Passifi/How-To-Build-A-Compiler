#pragma once
#include "astNode.h"
#include "lexer.h"
#include <cmath>
#include <memory>
#include <variant>

extern std::vector<TokenType> declarations;

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
  Token getCurrent();
  std::unique_ptr<SyntaxNode> parse();
  std::unique_ptr<Declaration> declaration();
  StmtPtr parseifStmt();
  StmtPtr parseWhileStmt();
  StmtPtr parseforStmt();
  StmtPtr statement();
  ExprPtr expression();
  ExprPtr equality();
  ExprPtr comparison();
  ExprPtr term();
  ExprPtr factor();
  ExprPtr unary();
  ExprPtr primary();
};
