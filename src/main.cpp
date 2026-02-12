#include "../include/FileHandler.h"
#include "../include/Loger.h"
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

int main(int argc, char **argv) {
  std::string data = "Basic Test String";
  Loger loger;
  loger.logError("Something bad happened");
  if (argc > 1) {
    data = FileHandler::getTextfileData(argv[1]);
  }
  Lexer lexer(data);
  auto lexems = lexer.getLexems();
  for (auto &lexem : lexems) {
    std::cout << lexem.toString() << std::endl;
  }
  return 0;
}
