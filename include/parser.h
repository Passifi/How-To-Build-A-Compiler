#pragma once 
#include <vector>
#include "../include/token.h"

class SyntaxTree {

};
class Parser {
  std::vector<Token>* _tokens;
  public:
    SyntaxTree parse(const std::vector<Token>& tokens);
      
};