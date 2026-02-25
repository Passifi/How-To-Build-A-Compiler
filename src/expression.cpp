#include "../include/expression.h"

std::string Unary::to_str() const {
  return "Unary\n   " + op.toString() + other->to_str();
}

std::string Literal::to_str() const {
  return

      "Literal: \n    " + value_Str(value);
}

std::string Grouping::to_str() const {
  return "Group\n     (" + expr.get()->to_str() + ")";
}
std::string Binary::to_str() const {
  return "Binary: \n    " + left.get()->to_str() + op.toString() +
         right.get()->to_str();
}
