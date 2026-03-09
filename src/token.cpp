#include "../include/NewToken.h"

std::string Token::to_string() {
  return std::string(token_to_string(type)) + ": " + literal;
}
