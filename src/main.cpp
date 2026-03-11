#include "../include/FileHandler.h"
#include "../include/lexer.h"
#include "../include/logger.h"
#include "../include/macros.h"
#include "../include/symbolTable.h"
#include <array>
#include <cctype>
#include <cinttypes>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <variant>
#include <vector>
int main(int argc, char **argv) {
  std::string data = "Basic Test String";
  Logger logger;
  if (argc > 1) {
    data = FileHandler::getTextfileData(argv[1]);
  }

  Lexer lexer(data);
  auto c = 'a';

  goto label;
  switch (c) {
  case 'a': {
  label:
  }
  default:
    goto label;
  }

  goto label;
  SymbolTable *root = new SymbolTable();
  root = root->pushTable();
  root = root->pushTable();
  root = root->pushTable();
  root = root->pushTable();
  root = root->popTable();
  root = root->popTable();
  root = root->popTable();
  root = root->popTable();
  root = root->popTable();
  root = root->popTable();
  auto lexems = lexer.getLexems();
  for (auto l : lexems) {
    std::cout << l.to_string() << std::endl;
  }
  return 0;
}
