#pragma once
#include <array>
#include <map>
#include <string>
enum class TokenType {
  UNKOWN,
  NUMBER,
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  LEFT_CURLY_BRACKET,
  RIGHT_CURLY_BRACKET,
  ASSIGN,
  EQUAL,
  NOT_EQUAL,
  LESS_EQUAL,
  GREATER_EQUAL,
  LESS,
  GREATER,
  ADD_ASSIGN,
  MULT_ASSIGN,
  SUB_ASSIGN,
  COMMA,
  DOT,
  MINUS,
  MINUSMINUS,
  PLUS,
  PLUSPLUS,
  STAR,
  SEMICOLON,
  SLASH,
  STRING,
  // keywords
  NULL_TOKEN,
  DEFINE,
  IFNDEFINE,
  ENDIF,
  IF,
  ELSE,
  ELSE_IF,
  WHILE,
  DO,
  RETURN,
  FOR,
  CONST,
  CLASS,
  STRUCT,
  TYPEDEF,
  IDENTIFIER,
  BANG,
  VOID,
  INT_TYPE,
  CHAR_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  LONG_TYPE,
  LONGLONG_TYPE,
  INT,
  CHAR,
  NEWLINE,
  FLOAT,
  DOUBLE,
  LONG,
  LONGLONG,
  UNSIGNED,
  UNION,
  HASH,
  INCLUDE,
  TOKEN_EOF,
  COUNT,
};
extern std::map<std::string, TokenType> keywords;

constexpr std::array<std::pair<TokenType, std::string_view>,
                     static_cast<size_t>(TokenType::COUNT)>
    token_strings = {{

        {TokenType::UNKOWN, "Unkown"},
        {TokenType::NUMBER, "Number"},
        {TokenType::LEFT_PAREN, "Left Parenthesis"},
        {TokenType::RIGHT_PAREN, "Right parenthesis"},
        {TokenType::LEFT_BRACKET, "Left Bracket"},
        {TokenType::RIGHT_BRACKET, "Right Bracket"},
        {TokenType::LEFT_CURLY_BRACKET, "Left Curly Bracket"},
        {TokenType::RIGHT_CURLY_BRACKET, "Right Curly Bracket"},
        {TokenType::ASSIGN, "Assign"},
        {TokenType::NEWLINE, "NEWLINE"},
        {TokenType::EQUAL, "Equal"},
        {TokenType::COMMA, "Comma"},
        {TokenType::DOT, "Dot"},
        {TokenType::MINUS, "Minus"},
        {TokenType::PLUS, "Plus"},
        {TokenType::STAR, "Star"},
        {TokenType::SEMICOLON, "Semicolon"},
        {TokenType::GREATER_EQUAL, "Greater Equal"},
        {TokenType::NOT_EQUAL, "Not Equal"},
        {TokenType::LESS, "Less Than"},
        {TokenType::LESS_EQUAL, "Less than or Equal"},
        {TokenType::GREATER, "Greater than"},
        {TokenType::ADD_ASSIGN, "Add and assign"},
        {TokenType::SUB_ASSIGN, "Subtract and assign"},
        {TokenType::MULT_ASSIGN, "Multiply and Assign"},
        {TokenType::STRING, "String"},
        {TokenType::VOID, "void"},
        {TokenType::FOR, "For"},
        {TokenType::IF, "IF"},
        {TokenType::ELSE_IF, "else if"},
        {TokenType::ELSE, "else"},
        {TokenType::CONST, "Const"},
        {TokenType::TYPEDEF, "typedef"},
        {TokenType::RETURN, "return"},
        {TokenType::DO, "Do"},
        {TokenType::STRUCT, "struct"},
        {TokenType::CLASS, "class"},
        {TokenType::IDENTIFIER, "identifier"},
        {TokenType::WHILE, "While"},
        {TokenType::INT, "int keyword"},
        {TokenType::CHAR, "char keyword"},
        {TokenType::FLOAT, "float keyword"},
        {TokenType::DOUBLE, "double keyword"},
        {TokenType::LONG, "long keyword"},
        {TokenType::LONGLONG, "long long keyword"},
        {TokenType::CHAR_TYPE, "type: char"},
        {TokenType::FLOAT_TYPE, "type: float"},
        {TokenType::DOUBLE_TYPE, "type: double"},
        {TokenType::LONG_TYPE, "type: long"},
        {TokenType::LONGLONG_TYPE, "type: long long"},
        {TokenType::UNION, "Union"},
        {TokenType::HASH, "#"},
        {TokenType::TOKEN_EOF, "Eof"},
        {TokenType::DEFINE, "Define"},
        {TokenType::IFNDEFINE, "If not define"},
        {TokenType::ENDIF, "end if"},
        {TokenType::INCLUDE, "Include"},
        {TokenType::INT_TYPE, "int"},
        {TokenType::UNSIGNED, "unsigned"},
        {TokenType::PLUSPLUS, "++"},
        {TokenType::MINUSMINUS, "--"},
        {TokenType::SLASH, "Slash"}}};

constexpr std::string_view token_to_string(TokenType t) {
  for (const auto &pair : token_strings) {
    if (pair.first == t) {
      return pair.second;
    }
  }
  return "Unkown";
}

class Token {
public:
  TokenType type;
  std::string literal;
  int line;
  Token(TokenType type) : type(type) { literal = token_to_string(type); }

  Token(TokenType type, std::string literal, int line)
      : type(type), literal(literal), line(line) {}

  std::string getLiteral();
  TokenType getType();
  std::string to_string();
};
