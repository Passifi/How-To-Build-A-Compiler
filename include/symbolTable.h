
#pragma once
#include <string>
#include <unordered_map>
class SymbolTable {

  std::unordered_map<std::string, std::string> symbols;

public:
  std::string hasSymbol(std::string literal);
};
