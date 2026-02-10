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
#define DEBUG
#ifdef DEBUG

#define printError(x) std::cout << x << std::endl;
#else

#define printError(x) ;
#endif // DEBUG

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
  COUNT,
};

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
        {TokenType::SLASH, "Slash"}

    }};

constexpr std::string_view token_to_string(TokenType t) {
  for (const auto &pair : token_strings) {
    if (pair.first == t) {
      return pair.second;
    }
  }
  return "Unkown";
}

std::map<std::string, TokenType> keywordsMap = {
    {"if", TokenType::IF},       {"else", TokenType::ELSE},
    {"while", TokenType::WHILE}, {"else if", TokenType::ELSE_IF},
    {"for", TokenType::FOR},     {"return", TokenType::RETURN}};

class Token {
  TokenType type;
  std::string lexeme;
  std::string literal; // as Binary
  unsigned int line;

public:
  Token(TokenType type, std::string lexeme, std::string literal, int line)
      : type(type), lexeme(lexeme), literal(literal), line(line) {}

  std::string toString() {
    return (std::string)token_to_string(type) + " " + lexeme + " " + literal +
           "Line No: " + std::to_string(line);
  }
};

bool isValidChar(char c) {
  const std::string specialCharacters = ".<>\"{}()[]";
  for (auto el : specialCharacters) {
    if (c == el)
      return true;
  }
  return isalnum(c);
}

class FileHandler {
public:
  FileHandler() {}

  static std::string getTextfileData(std::string path) {
    constexpr auto read_size = std::size_t(4096); // define a chunk to read in.

    std::ifstream file(path);
    if (!file.is_open()) {
      printError("File Loading Failed");
      std::cout << "Couldn't load file: " << path << std::endl;
      return "";
    }
    auto out = std::string();
    auto buf =
        std::string(read_size, '\0'); // Define a buffer of read_size that ends
                                      // in '\0' for proper string termination
    while (file.read(&buf[0], read_size)) {
      out.append(buf, 0, file.gcount()); // what is g count exactly?
    }

    out.append(buf, 0, file.gcount());
    return out;
  }
};

class Lexer {

public:
  int start;
  int current;
  int line;

  std::vector<Token> lexems;
  std::string data;
  Lexer(std::string &data) : data(data) {}
  std::vector<Token> getLexems() {
    lexems.clear();
    std::string currentString;
    current = 0;
    line = 1;
    while (!isAtEnd()) {
      char c = advance();
      switch (c) {

      case '(':
        lexems.push_back({TokenType::LEFT_PAREN, "", "", line});
        break;
      case ')':
        lexems.push_back({TokenType::RIGHT_PAREN, "", "", line});
        break;
      case '[':
        lexems.push_back({TokenType::LEFT_BRACKET, "", "", line});
        break;
      case ']':
        lexems.push_back({TokenType::RIGHT_BRACKET, "", "", line});
        break;
      case '{':
        lexems.push_back({TokenType::LEFT_CURLY_BRACKET, "", "", line});
        break;
      case '}':
        lexems.push_back({TokenType::RIGHT_CURLY_BRACKET, "", "", line});
        break;
      case '=': {
        TokenType t = match('=') ? TokenType::EQUAL : TokenType::ASSIGN;
        lexems.push_back({t, "", "", line});
        break;
      }
      case '<': {
        TokenType t = match('=') ? TokenType::LESS_EQUAL : TokenType::LESS;
        lexems.push_back({t, "", "", line});
        break;
      }
      case '>': {
        TokenType t =
            match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER;
        lexems.push_back({t, "", "", line});
        break;
      }
      case '"': {
        start = current;
        string();
        break;
      }
      case '*': {
        TokenType t = match('=') ? TokenType::MULT_ASSIGN : TokenType::STAR;
        lexems.push_back({t, "", "", line});
        break;
      }
      case '+': {
        TokenType t = match('=') ? TokenType::ADD_ASSIGN : TokenType::PLUS;
        lexems.push_back({t, "", "", line});
      }
      case ';':
        lexems.push_back({TokenType::SEMICOLON, "", "", line});
        break;
      case '-': {
        TokenType t = match('=') ? TokenType::SUB_ASSIGN : TokenType::MINUS;
        lexems.push_back({t, "", "", line});
        break;
      }
      case '/': {
        if (match('/')) {
          while (peek() != '\n' && !isAtEnd())
            advance();
        } else {
          lexems.push_back({TokenType::SLASH, "", "", line});
        }
        break;
      }
      case '\n':
        line++;
        break;
      default:
        if (isdigit(c)) {
          start = current;
          number();
        }
        printError("Unexpected Character/Keyword")
        // return lexems;
      }
    }
    return lexems;
  }

private:
  bool isAtEnd() { return current >= data.length(); }
  char advance() { return data[current++]; }
  void number() {
    while (isdigit(peek())) {
      advance();
    }
    if (peek() == '.' && isdigit(peekNext())) {
      advance();
      while (isdigit(peek()))
        advance();
    }
    std::string value = data.substr(start - 1, (current - start) + 1);
    lexems.push_back({TokenType::NUMBER, value, value, line});
  }
  bool match(char expected) {
    if (isAtEnd()) {
      return false;
    }
    if (data[current] != expected)
      return false;
    current++;
    return true;
  }
  char peek() {
    if (isAtEnd()) {
      return '\0';
    } else
      return data[current];
  }
  char peekNext() {
    int currentBuffer = current;
    advance();
    if (isAtEnd()) {
      current = currentBuffer;
      return '\0';
    } else
      current = currentBuffer;
    return data[current + 1];
  }

  void string() {
    while (peek() != '"' && !isAtEnd()) {
      if (peek() == '\n')
        line++;
      advance();
    }
    advance();
    std::string value = data.substr(start, (current - start - 1));
    lexems.push_back({TokenType::STRING, value, value, line});
  }
};

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
  return 0;
}
