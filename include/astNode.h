#ifndef ASTNODE_H
#include <iostream>
#include <string>
#define ASTNODE_H

class AstNode {
public:
  AstNode();
  ~AstNode();

  virtual std::string get_str() const = 0;
};

class CodeBlock : public AstNode {

public:
private:
};

class Expression : public AstNode {};

class Statement : public AstNode {};

#endif
