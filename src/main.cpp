#include "../include/FileHandler.h"
#include "../include/lexer.h"
#include "../include/macros.h"
#include "../include/parser.h"
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
  if (argc > 1) {
    data = FileHandler::getTextfileData(argv[1]);
  }

  Lexer lexer(data);
  auto lexems = lexer.getLexems();
    for (auto &lexem : lexems) {
    std::cout << lexem.toString() << std::endl;
    }
  Parser parser;
  SyntaxTree syntax = parser.parse(lexems);
  // Semantics semantics;
  // Meaning meaning = semantics.analyze(syntax);
  // ICodeGen iCodeGen; 
  // IntermittentRepresentation ir = iCodeGen.generate(meaning);
  // Optimizer optimizer; 
  // optimizer.optimize(level, ir);
  // struct architecture; 
  // architecture.cpu = InstructionSet::X86; 
  // AssemblyConverter converter(&architecture);
  // converter.createASM(ir);
  return 0;
}
