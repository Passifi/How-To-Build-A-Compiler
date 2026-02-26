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

class Statement : public Expr {
public:
  Statement(Token keywordToken, ExprPtr group, ExprPtr expression)
      : keyword(keywordToken), group(std::move(group)),
        expression(std::move(expression)) {}
  Token keyword;
  std::unique_ptr<Expr> group;
  std::unique_ptr<Expr> expression;
};

class Binary : public Expr {
public:
  Binary(ExprPtr left, Token token, ExprPtr right)
      : op(token), left(std::move(left)), right(std::move(right)) {}
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
