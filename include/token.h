#include <map>
#include <array>

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
  PLUS,
  STAR,
  SEMICOLON,
  SLASH,
  STRING,
  NPERCENT,
  // keywords
  NULL_TOKEN,
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
  INT_TYPE,
  CHAR_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  LONG_TYPE,
  LONGLONG_TYPE,
  
  INT,
  CHAR,
  FLOAT,
  DOUBLE,
  LONG,
  LONGLONG,
  UNSIGNED,
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
        {TokenType::EQUAL, "Equal"},
        {TokenType::COMMA, "Comma"},
        {TokenType::NPERCENT,"&"},
        {TokenType::DOT, "Dot"},
        {TokenType::MINUS, "Minus"},
        {TokenType::PLUS, "Plus"},
        {TokenType::STAR, "Star"},
        {TokenType::SEMICOLON, "Semicolon"},
        {TokenType::GREATER_EQUAL, "Greater Equal"},
        {TokenType::LESS, "Less Than"},
        {TokenType::LESS_EQUAL, "Less than or Equal"},
        {TokenType::GREATER, "Greater than"},
        {TokenType::ADD_ASSIGN, "Add and assign"},
        {TokenType::SUB_ASSIGN, "Subtract and assign"},
        {TokenType::MULT_ASSIGN, "Multiply and Assign"},
        {TokenType::STRING, "String"},
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
        {TokenType::INT, "int"},
        {TokenType::CHAR, "char"},
        {TokenType::FLOAT, "float"},
        {TokenType::DOUBLE, "double"},
        {TokenType::LONG, "long"},
        {TokenType::LONGLONG, "long long"},
        {TokenType::CHAR_TYPE, "type: char"},
        {TokenType::FLOAT_TYPE, "type: float"},
        {TokenType::DOUBLE_TYPE, "type: double"},
        {TokenType::LONG_TYPE, "type: long"},
        {TokenType::LONGLONG_TYPE, "type: long long"},
        {TokenType::UNSIGNED, "unsigned"},
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
  TokenType type;
  std::string literal; 
  unsigned int line;
public:
  bool failedLexing = false;
  std::string failureInfo; 
  Token(TokenType type, std::string literal, int line)
      : type(type), literal(literal), line(line) {}
  Token(TokenType type ,int line)
      : type(type),literal(""), line(line) {}
      TokenType getToken() { return this->type; }
  Token(TokenType type, int line, std::string failureInfo) : type(type), line(line), literal(""), failedLexing(true), failureInfo(failureInfo) {

  }
  std::string toString() {

    
    return "TokenType: " + (std::string)token_to_string(type) + " Literal: " + literal +
           "\n Line No: " + std::to_string(line);
  }
  
};
