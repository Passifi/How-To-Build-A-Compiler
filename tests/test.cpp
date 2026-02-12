#include "../include/FileHandler.h"
#include "../include/lexer.h"
#include <iostream>
int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Please provide a testfile!" << std::endl;
  }
  // note for later -> provide a byte file and a c file and compare the resultss
  //

  FileHandler fileHandler;
  auto data = fileHandler.getTextfileData(argv[2]);
  Lexer lexer(data);
  auto tokens = lexer.getLexems();

  return 0;
}
