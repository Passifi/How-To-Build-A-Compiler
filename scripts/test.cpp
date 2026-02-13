#include <array>
#include <string_view>

enum TokenType {
  IF,
  ELSE,
  THEN,
  WHILE,
  PLUS,
  MINUS,
  STAR,
  SEMICOLON,
};
std::array<std::pair<TokenType, std::string_view>, 8> token_to_string = {{
    {TokenType::IF, "IF"},
    {TokenType::ELSE, "ELSE"},
    {TokenType::THEN, "THEN"},
    {TokenType::WHILE, "WHILE"},
    {TokenType::PLUS, "PLUS"},
    {TokenType::MINUS, "MINUS"},
    {TokenType::STAR, "STAR"},
    {TokenType::SEMICOLON, "SEMICOLON"},
}};
