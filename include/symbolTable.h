
#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class SymbolTable {
  SymbolTable *parent = nullptr;
  std::unordered_set<std::string, int> symbols;
  std::vector<std::string> values;

public:
  SymbolTable *pushTable() {
    SymbolTable *table = new SymbolTable();
    table->parent = this;
    return table;
  }
  SymbolTable *popTable() {
    auto parent = this->parent;
    if (parent == nullptr) {

      std::cout << "Couldn't pop the table root node reached" << std::endl;
      parent = this;
    } else {
      delete this;
    }
    return parent;
  }
};
