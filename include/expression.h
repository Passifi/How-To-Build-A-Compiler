#pragma once
#include "../include/lexer.h"
#include <cmath>
#include <memory>
#include <variant>

class Expr {
public:
  virtual std::string to_str() const = 0;
};

using ExprPtr = std::unique_ptr<Expr>;

class Unary : public Expr {
public:
  Unary(Token currentToken, ExprPtr other)
      : op(currentToken), other(std::move(other)) {}
  Token op;
  std::unique_ptr<Expr> other;
  std::string to_str() const override;
};

class Literal : public Expr {
public:
  Literal(Value val) : value(val) {}

  Value value;
  std::string to_str() const override;
};

class Binary : public Expr {
public:
  Binary(ExprPtr left, Token token, ExprPtr right)
      : left(std::move(left)), right(std::move(right)), op(token) {}
  Token op;
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;
  std::string to_str() const override;
};

class Grouping : public Expr {
public:
  Grouping(ExprPtr expr) : expr(std::move(expr)) {}
  std::unique_ptr<Expr> expr;
  std::string to_str() const override;
};
