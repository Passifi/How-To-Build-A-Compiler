#include "lexer.h"
#include <cmath>
#include <variant>
using Value = std::variant<int, double, float, char, std::string, bool>;
class Expr {
public:
  virtual std::string to_str() = 0;
};

class Unary : public Expr {

  Token op;
  Expr *other;
  std::string to_str() { return op.toString() + other->to_str(); }
};

class Literal : public Expr {

  Token op;
  std::string to_str() { return op.toString(); }
};

class Binary : public Expr {
  Token op;
  Expr *left;
  Expr *right;
  std::string to_str() {
    return left->to_str() + op.toString() + right->to_str();
  }
};

class Grouping : public Expr {

  Expr *expr;

  std::string to_str() { return "(" + expr->to_str() + ")"; }
};

struct Node {
  std::vector<Node *> nodes;
  Expr *expr;
  std::string to_str() {
    std::string result = expr->to_str() + "\n";
    for (auto n : nodes) {
      result += n->to_str() + "";
    }
    return result;
  }
};

// Expr lowest node -> it will return a value of sorts?
// else it will return anokenther expression
