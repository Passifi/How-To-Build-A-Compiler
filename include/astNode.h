#ifndef ASTNODE_H
#include "token.h"
#include <iostream>
#include <memory>
#include <string>
#include <variant>
#define ASTNODE_H

class SyntaxNode {
public:
  SyntaxNode();
  ~SyntaxNode();

  virtual std::string to_str() const = 0;
};

class RootNode : public SyntaxNode {

  std::vector<std::unique_ptr<SyntaxNode>> subNodes;
};

class Block : public SyntaxNode {
public:
private:
};

class Expr : public SyntaxNode {

public:
  Expr() {}
};

class Statement : public SyntaxNode {};
using SyntaxNodePtr = std::unique_ptr<SyntaxNode>;
using StmtPtr = std::unique_ptr<Statement>;
using ExprPtr = std::unique_ptr<Expr>;
class ExprStatement : public Statement {
  ExprPtr expression;

public:
  ExprStatement(ExprPtr expression) : expression(std::move(expression)) {}
  std::string to_str() const override;
};

class Unary : public Expr {
public:
  Unary(Token currentToken, ExprPtr other)
      : op(currentToken), other(std::move(other)) {}
  Token op;
  std::unique_ptr<SyntaxNode> other;
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
  std::unique_ptr<SyntaxNode> left;
  std::unique_ptr<SyntaxNode> right;
  std::string to_str() const override;
};

class Grouping : public Expr {
public:
  Grouping(ExprPtr expr) : expr(std::move(expr)) {}
  std::unique_ptr<SyntaxNode> expr;
  std::string to_str() const override;
};

class Declaration : public Statement {};
class IfStmt : public Statement {
public:
  std::unique_ptr<Expr> condition;
  std::unique_ptr<SyntaxNode> block;
  std::unique_ptr<SyntaxNode> elseBlock;
};
class WhileStmt : public Statement {
  std::unique_ptr<Expr> condition;
  std::unique_ptr<SyntaxNode> block;
};
class ForStmt : public Statement {
  std::unique_ptr<Statement> initializer;
  std::unique_ptr<Expr> condition;
  std::unique_ptr<Expr> iterator;
  std::unique_ptr<SyntaxNode> block;
};

#endif
