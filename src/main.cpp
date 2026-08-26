#include "../include/FileHandler.h"
#include "../include/logger.h"
#include "../include/lexer.h"
#include "../include/macros.h"
#include <array>
#include <cctype>
#include <cinttypes>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>
#include <variant>
int main(int argc, char **argv) {
  
  std::string data = "Basic Test String";
  if (argc > 1) {
    data = FileHandler::getTextfileData(argv[1]);
  }
  Lexer lexer(data);
  try {
  auto lexems = lexer.getLexems();
    for (auto &lexem : lexems) {
    std::cout << lexem.toString() << std::endl;
  }
  }
  catch(exception ex) {
    std::cout << ex.what() << std::endl;
  }

  return 0;
}
