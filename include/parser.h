#pragma once
#include "lexer.h"
#include <cmath>
#include <memory>
#include <variant>

class Expr {
public:
  virtual std::string to_str() = 0;
};

using ExprPtr = std::unique_ptr<Expr>;
class Unary : public Expr {
public:
  Unary(Token currentToken, ExprPtr other)
      : op(currentToken), other(std::move(other)) {}
  Token op;
  std::unique_ptr<Expr> other;
  std::string to_str() { return "Unary\n" + op.toString() + other->to_str(); }
};

class Literal : public Expr {
public:
  Literal(Value val) : value(val) {}

  Value value;
  std::string to_str() {
    return

        "Literal" + value_Str(value);
  }
};

class Binary : public Expr {
public:
  Binary(ExprPtr left, Token token, ExprPtr right)
      : left(std::move(left)), right(std::move(right)), op(token) {}
  Token op;
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;
  std::string to_str() {
    return "Binary: \n" + left.get()->to_str() + op.toString() +
           right.get()->to_str();
  }
};

class Grouping : public Expr {
public:
  Grouping(ExprPtr expr) : expr(std::move(expr)) {}
  std::unique_ptr<Expr> expr;
  std::string to_str() { return "(" + expr.get()->to_str() + ")"; }
};

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
  ExprPtr expression();
  ExprPtr equality();
  ExprPtr comparison();
  ExprPtr term();
  ExprPtr factor();
  ExprPtr unary();
  ExprPtr primary();
};
