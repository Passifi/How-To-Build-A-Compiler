#include "../include/FileHandler.h"
#include "../include/lexer.h"
#include "../include/logger.h"
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
#include <variant>
#include <vector>

int main(int argc, char **argv) {
  std::string data = "Basic Test String";
  Logger logger;
  logger.logError("Something bad happened");
  if (argc > 1) {
    data = FileHandler::getTextfileData(argv[1]);
  }
  Lexer lexer(data);
  auto lexems = lexer.getLexems();
  return 0;
}
