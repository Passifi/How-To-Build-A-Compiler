#include "../include/lexer.h"

Lexer::Lexer(std::string &data) : data(data) {}
std::vector<Token> Lexer::getLexems() {
  lexems.clear();
  std::string currentString;
  current = 0;
  line = 1;
  while (!isAtEnd()) {
    char c = advance();
    std::cout << c << std::endl;
    switch (c) {
    case '(':
      lexems.push_back({TokenType::LEFT_PAREN,  line});
      
      break;
    case ')':
      lexems.push_back({TokenType::RIGHT_PAREN,  line});
      break;
    case '[':
      lexems.push_back({TokenType::LEFT_BRACKET,  line});
      break;
    case ']':
      lexems.push_back({TokenType::RIGHT_BRACKET,   line});
      break;
    case '{':
      lexems.push_back({TokenType::LEFT_CURLY_BRACKET,   line});
      break;
    case '}':
      lexems.push_back({TokenType::RIGHT_CURLY_BRACKET,  line});
      break;
    case '=': {
      TokenType t = match('=') ? TokenType::EQUAL : TokenType::ASSIGN;
      lexems.push_back({t, line});
      break;
    }
    case ',':
      lexems.push_back({TokenType::COMMA, line});
      break;
    case '<': {
      TokenType t = match('=') ? TokenType::LESS_EQUAL : TokenType::LESS;
      std::cout << token_to_string(t) << std::endl; 
      try {
      lexems.push_back({t, line});
      }
      catch(std::exception ex) {
        
      }
      break;
    }
    case '>': {
      TokenType t = match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER;
      lexems.push_back({t, line});
      break;
    }
    case '"': {
      start = current;
      string();
      break;
    }
    case '*': {
      TokenType t = match('=') ? TokenType::MULT_ASSIGN : TokenType::STAR;
      lexems.push_back({t,  line});
      break;
    }
    case '+': {
      TokenType t = match('=') ? TokenType::ADD_ASSIGN : TokenType::PLUS;
      lexems.push_back({t, line});
      break;
    }
    case ';':
      lexems.push_back({TokenType::SEMICOLON, line});
      break;
    case '-': {
      TokenType t = match('=') ? TokenType::SUB_ASSIGN : TokenType::MINUS;
      lexems.push_back({t, line});
      break;
    }
    case '#': {
        while(peek() != '\n' && !isAtEnd()) {
          advance();
        }
        break;
    }
    case '/': {
      if (match('/')) {
        while (peek() != '\n' && !isAtEnd())
          advance();
      } else {
        lexems.push_back({TokenType::SLASH, line});
      }
      break;
    }
    case '\n':
      line++;
      break;
    default:
      if (isalpha(c)) {
        std::cout << "Going in " << std::endl; 
        start = current;
        identifier();
      }
      else if (isdigit(c)) {
        start = current;
        number();
        break;
      }
      //printError("Unexpected Character/Keyword")
      //printError(c);
      // return lexems;
    }
  }
  return lexems;
}

std::map<std::string, TokenType> keywords = {
    {"for", TokenType::FOR},
    {"do", TokenType::DO},
    {"while", TokenType::WHILE},
    {"if", TokenType::IF},
    {"else", TokenType::ELSE},
    {"else if", TokenType::ELSE_IF},
    {"struct", TokenType::STRUCT},
    {"class", TokenType::CLASS},
    {"const", TokenType::CONST},
    {"typedef", TokenType::TYPEDEF},
    {"return", TokenType::RETURN},
    {"int", TokenType::INT},
    {"char", TokenType::CHAR},
    {"float", TokenType::FLOAT},
    {"double", TokenType::DOUBLE},
    {"long", TokenType::LONG},
    {"long long", TokenType::LONGLONG},
    {"unsigned", TokenType::UNSIGNED},
    {"NULL", TokenType::NULL_TOKEN},

};

bool Lexer::isAtEnd() { return current >= static_cast<int>(data.length()); }
char Lexer::advance() { return data[current++]; }

bool Lexer::match(char expected) {
  if (isAtEnd()) {
    return false;
  }
  if (data[current] != expected)
    return false;
  current++;
  return true;
}
char Lexer::peek() {
  if (isAtEnd()) {
    return '\0';
  } else
    return data[current];
}
char Lexer::peekNext() {
  int currentBuffer = current;
  advance();
  if (isAtEnd()) {
    current = currentBuffer;
    return '\0';
  } else
    current = currentBuffer;
  return data[current + 1];
}
void Lexer::identifier() {
  while(isalpha(peek())) {
    advance();
  }
  std::string value = data.substr(start-1,(current-start+1));
  lexems.push_back({TokenType::IDENTIFIER,value,line});
}

void Lexer::number() {
  while(isdigit(peek())) {
    advance();
  }
  if(peek() == '.') {
    advance();
    while(isdigit(peek())) {
      advance();
    }
  }
  std::string value = data.substr(start-1,(current-start)+1);
  lexems.push_back({TokenType::NUMBER,value,line});
}

void Lexer::string() {
  while (peek() != '"' && !isAtEnd()) {
    if (peek() == '\n')
      line++;
    advance();
  }
  advance();
  std::string value = data.substr(start, (current - start - 1));
  lexems.push_back({TokenType::STRING, value, line});
}
