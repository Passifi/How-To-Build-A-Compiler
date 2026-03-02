#pragma once
#include "../include/lexer.h"
#include <cmath>
#include <memory>
#include <variant>

class Expr {
public:
  virtual std::string to_str() const = 0;
};
