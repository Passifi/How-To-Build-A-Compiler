#include <array>
#include <cctype>
#include <cinttypes>
#include <cstddef>
#include <fstream>
#include <iostream>
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
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  LEFT_CURLY_BRACKET,
  RIGHT_CURLY_BRACKET,
  ASSIGN,
  EQUAL,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  STAR,
  SEMICOLON,
  COUNT,
};

constexpr std::array<std::pair<TokenType, std::string_view>,
                     static_cast<size_t>(TokenType::COUNT)>
    token_strings = {{

        {TokenType::UNKOWN, "Unkown"},
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
        {TokenType::SEMICOLON, "Semilcolon"},
    }};

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
  std::string lexeme;
  std::string literal;
  unsigned int line;

public:
  Token(TokenType type, std::string lexeme, std::string literal, int line)
      : type(type), lexeme(lexeme), literal(literal), line(line) {}
  std::string toString() {
    return (std::string)token_to_string(type) + " " + lexeme + " " + literal;
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
  int current;
  int line;
  std::string data;
  Lexer(std::string &data) : data(data) {}
  std::vector<Token> getLexems() {
    std::vector<Token> lexems;
    std::string currentString;
    current = 0;
    line = 1;
    int start = 0;
    while (!isAtEnd()) {

      switch (advance()) {
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
      case '=':
        lexems.push_back({TokenType::ASSIGN, "", "", line});
        break;
      case '*':
        lexems.push_back({TokenType::STAR, "", "", line});
        break;
      case ';':
        lexems.push_back({TokenType::SEMICOLON, "", "", line});
        break;
      case '-':
        lexems.push_back({TokenType::MINUS, "", "", line});
        break;
      case '\n':
        line++;
        break;
      default:
        lexems.push_back({TokenType::UNKOWN, "", "", line});
      }
    }
    return lexems;
  }

private:
  bool isAtEnd() { return current >= data.length(); }
  char advance() { return data[current++]; }
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
