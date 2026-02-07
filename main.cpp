#include <cctype>
#include <cinttypes>
#include <cstddef>
#include <string> 
#include <iostream>
#include <vector> 
#include <fstream>
#include <array>
#include <string_view>
enum class Token {
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

constexpr std::array<std::pair<Token, std::string_view>, static_cast<size_t>(Token::COUNT)>  token_strings = {{
  
  {Token::UNKOWN,"Unkown" },
  {Token::LEFT_PAREN,"Left Parenthesis" },
  {Token::RIGHT_PAREN, "Right parenthesis"},
  {Token::LEFT_BRACKET,"Left Bracket"},
  {Token::RIGHT_BRACKET, "Right Bracket"},
  {Token::LEFT_CURLY_BRACKET, "Left Curly Bracket"},
  {Token::RIGHT_CURLY_BRACKET,"Right Curly Bracket"},
  {Token::ASSIGN, "Assign"},
  {Token::EQUAL,"Equal"},
  {Token::COMMA,"Comma"},
  {Token::DOT,"Dot"},
  {Token::MINUS,"Minus"},
  {Token::PLUS,"Plus"},
  {Token::STAR,"Star"},
  {Token::SEMICOLON,"Semilcolon"},}
};

constexpr std::string_view token_to_string(Token t) {
  for(const auto& pair : token_strings) {
    if(pair.first == t) {
      return pair.second;
    }
  }
  return "Unkown";
}


bool isValidChar(char c) {
  const std::string specialCharacters = ".<>\"{}()[]"; 
  for(auto el : specialCharacters) {
    if(c == el) return true;
  }
  return  isalnum(c);
}

class FileHandler {
  public:
    FileHandler() {}

  static std::string getTextfileData(std::string path)  {
    constexpr auto read_size = std::size_t(4096); // define a chunk to read in.
    
    std::ifstream file(path);
    if(!file.is_open()) {
      std::cout << "Couldn't load file: " << path << std::endl;
      return ""; 
    }
    auto out = std::string();
    auto buf = std::string(read_size,'\0'); // Define a buffer of read_size that ends in '\0' for proper string termination
    
    while(file.read(&buf[0], read_size)) {
      out.append(buf,0,file.gcount()); // what is g count exactly? 
    } 

    out.append(buf,0, file.gcount());
    return out;
  }

};


class Lexer {
  
  public:
    Lexer() {}
  static std::vector<Token> getLexems(std::string data) {
    std::vector<Token> lexems;
    std::string currentString;
      for(auto c : data) {
        if(isalnum(c)) {
          currentString+=c;
          // check whether delimiter
          // delimiter then
        }
        else {
            if(c != ' ' || c != '\n')
            lexems.push_back(getToken(c));
             
        }
      }
    
      
    return lexems;
  }
  
  private:

    static Token getToken(char c) {
      switch(c) {
        case '(':
          return Token::LEFT_PAREN;
        case ')':
          return Token::RIGHT_PAREN;
        case '[':
          return Token::LEFT_BRACKET;
        case ']':
          return Token::RIGHT_BRACKET;
        case '{':
          return Token::LEFT_CURLY_BRACKET;
        case '}':
          return Token::RIGHT_CURLY_BRACKET;
        case '=':
          return Token::ASSIGN;
        case '*':
          return Token::STAR;
        case ';':
          return Token::SEMICOLON;
        case '-':
          return Token::MINUS;
        default:
          return Token::UNKOWN;
      }
    }
    Token getToken(std::string token) {
      return Token::UNKOWN; 
    }
};


int main(int argc, char** argv) {
  std::string data = "there is no god";
  if(argc > 1) {
   data = FileHandler::getTextfileData(argv[1]); 
  }
  auto lexems = Lexer::getLexems(data);

  for(auto& lexem : lexems) {
    std::cout << token_to_string(lexem) << std::endl;
  }

  return 0;
} 
