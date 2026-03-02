#ifndef ASTNODE_H
#include "token.h"
#include <iostream>
#include <memory>
#include <string>
#include <variant>
#define ASTNODE_H

class AstNode {
public:
  AstNode();
  ~AstNode();

  virtual std::string to_str() const = 0;
};

class RootNode : public AstNode {};

class Block : public AstNode {
public:
  std::vector<std::unique_ptr<AstNode>> subNodes;

private:
};

class Expr : public AstNode {};
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
class Statement : public AstNode {};

class Declaration : public Statement {};
class IfStmt : public Statement {
public:
  std::unique_ptr<Expr> condition;
  std::unique_ptr<Block> block;
  std::unique_ptr<Block> elseBlock;
};
class WhileStmt : public Statement {
  std::unique_ptr<Expr> condition;
  std::unique_ptr<Block> block;
};
class ForStmt : public Statement {
  std::unique_ptr<Statement> initializer;
  std::unique_ptr<Expr> condition;
  std::unique_ptr<Expr> iterator;
  std::unique_ptr<Block> block;
};

#endif
