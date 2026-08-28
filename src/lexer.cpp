#include "../include/lexer.h"
std::map<std::string, TokenType> keywords = {
    {"for", TokenType::FOR},           {"do", TokenType::DO},
    {"while", TokenType::WHILE},       {"if", TokenType::IF},
    {"else", TokenType::ELSE},         {"else if", TokenType::ELSE_IF},
    {"struct", TokenType::STRUCT},     {"class", TokenType::CLASS},
    {"const", TokenType::CONST},       {"typedef", TokenType::TYPEDEF},
    {"return", TokenType::RETURN},     {"union", TokenType::UNION},
    {"define", TokenType::DEFINE},     {"ifndef", TokenType::IFNDEFINE},
    {"endif", TokenType::ENDIF},       {"include", TokenType::INCLUDE},

    {"int", TokenType::INT},           {"char", TokenType::CHAR},
    {"float", TokenType::FLOAT},       {"double", TokenType::DOUBLE},
    {"long", TokenType::LONG},         {"long long", TokenType::LONGLONG},
    {"unsigned", TokenType::UNSIGNED}, {"NULL", TokenType::NULL_TOKEN},
    {"void", TokenType::VOID}

};
Lexer::Lexer(std::string &data) : data(data) {}
std::vector<Token> Lexer::getLexems() {
  lexems.clear();
  std::string currentString;
  current = 0;
  line = 1;
  while (!isAtEnd()) {
    char c = advance();
    switch (c) {
<<<<<<< HEAD
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
    case ',':
      lexems.push_back({TokenType::COMMA, line});
      break;
    case ';':
      lexems.push_back({TokenType::SEMICOLON, line});
      break;
    case '&':
      lexems.push_back({TokenType::NPERCENT,line});
      break;
    case '\'': {
      if(isalpha(peek())) {
        std::string value = "";
        value += advance();
        lexems.push_back({TokenType::CHAR,value,line});
        // check if ' otherwise throw parsing error 
        advance();
      }
      break;
    }
    case '=': {
      TokenType t = match('=') ? TokenType::EQUAL : TokenType::ASSIGN;
      lexems.push_back({t, line});
=======
    case '#':
      while (peek() != '\n') {
        advance();
      }
      break;
    case '(':
      lexems.push_back({TokenType::LEFT_PAREN, "(", line});
      break;
    case ')':
      lexems.push_back({TokenType::RIGHT_PAREN, ")", line});
      break;
    case '[':
      lexems.push_back({TokenType::LEFT_BRACKET, "[", line});
      break;
    case ']':
      lexems.push_back({TokenType::RIGHT_BRACKET, "]", line});
      break;
    case '{':
      lexems.push_back({TokenType::LEFT_CURLY_BRACKET, "{", line});
      break;
    case '}':
      lexems.push_back({TokenType::RIGHT_CURLY_BRACKET, "}", line});
      break;
    case '=': {
      TokenType t = match('=') ? TokenType::EQUAL : TokenType::ASSIGN;
      lexems.push_back({t, "=", line});
      break;
    }
    case ',':
      lexems.push_back({TokenType::COMMA, ",", line});
>>>>>>> 9d9d129764935a7aa4cccd45b4d079f84ecb2e0f
      break;
    }
    case '<': {
      TokenType t = match('=') ? TokenType::LESS_EQUAL : TokenType::LESS;
<<<<<<< HEAD
      std::cout << token_to_string(t) << std::endl; 
      lexems.push_back({t, line});
=======
      lexems.push_back({t, "<=", line});
>>>>>>> 9d9d129764935a7aa4cccd45b4d079f84ecb2e0f
      break;
    }
    case '>': {
      TokenType t = match('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER;
<<<<<<< HEAD
      lexems.push_back({t, line});
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
    case '-': {
      TokenType t = match('=') ? TokenType::SUB_ASSIGN : TokenType::MINUS;
      lexems.push_back({t, line});
=======
      lexems.push_back({t, ">=", line});
>>>>>>> 9d9d129764935a7aa4cccd45b4d079f84ecb2e0f
      break;
    }
    case '"': {
      start = current;
      string();
      break;
    }
<<<<<<< HEAD
    case '#': {
        while(peek() != '\n' && !isAtEnd()) {
          advance();
        }
        break;
=======
    case '*': {
      TokenType t = match('=') ? TokenType::MULT_ASSIGN : TokenType::STAR;
      if (t == TokenType::STAR)
        lexems.push_back({t, "*", line});
      else
        lexems.push_back({t, "*=", line});
      break;
    }
    case '+': {
      TokenType t = TokenType::PLUS;
      std::string lit = "+";
      if (match('+')) {
        t = TokenType::PLUSPLUS;
        lit += "+";
      } else if (match('=')) {
        t = TokenType::ADD_ASSIGN;
        lit += "=";
      }
      lexems.push_back({t, lit, line});
      break;
    }
    case ';':
      lexems.push_back({TokenType::SEMICOLON, "", line});
      break;
    case '-': {
      TokenType t = match('=') ? TokenType::SUB_ASSIGN : TokenType::MINUS;
      if (t == TokenType::MINUS)
        lexems.push_back({t, "-", line});
      else
        lexems.push_back({t, "-=", line});

      break;
>>>>>>> 9d9d129764935a7aa4cccd45b4d079f84ecb2e0f
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
      lexems.push_back(TokenType::NEWLINE);
      line++;
      break;
    case EOF:
      lexems.push_back({TokenType::TOKEN_EOF});
      break;
    default:
      if (isalpha(c) || c == '_') {
        start = current;
        identifier();
      }
      else if (isdigit(c)) {
        start = current;
        number();
      }
<<<<<<< HEAD
      else {
        // unexpected token throw error
        // shouldn't really happen here though... 
      }
=======
      // printError("Unexpected Character/Keyword")
      // return lexems;
>>>>>>> 9d9d129764935a7aa4cccd45b4d079f84ecb2e0f
    }
  }
  lexems.push_back(TokenType::TOKEN_EOF);
  return lexems;
}

<<<<<<< HEAD
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

=======
bool Lexer::isAtEnd() { return (size_t)current >= data.length(); }
char Lexer::advance() { return data[current++]; }
void Lexer::number() {
  while (isdigit(peek())) {
    advance();
  }
  if (peek() == '.' && isdigit(peekNext())) {
    advance();
    while (isdigit(peek()))
      advance();
    if (peek() == 'f') {
      advance();
    }
  }

  std::string value = data.substr(start - 1, (current - start) + 1);

  lexems.push_back({TokenType::INT_TYPE, value, line});
}
void Lexer::identifier() {
  while (isalpha(peek())) {
    advance();
  }
  std::string value = data.substr(start - 1, (current - start) + 1);
  if (keywords.count(value) > 0) {
    lexems.push_back({keywords[value], value, line});
  } else {
    lexems.push_back({TokenType::IDENTIFIER, value, line});
  }
}
>>>>>>> 9d9d129764935a7aa4cccd45b4d079f84ecb2e0f
bool Lexer::match(char expected) {
  if (isAtEnd()) {
    return false;
  }
  if (peek() != expected)
    return false;
  advance();
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
  while(isValidIdentifiter(peek())) {
    advance();
  }
  std::string value = data.substr(start-1,(current-start+1));
  if(keywords.count(value) > 0) {
    lexems.push_back({keywords[value],line});
  }
  else {
  lexems.push_back({TokenType::IDENTIFIER,value,line});
  }
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
    std::string s = "hello world "
                    "hello";
    char c = advance();
    if (c == '\\' && !isAtEnd() && peek() == '"')
      advance();
  }
  advance();
  std::string value = data.substr(start, (current - start - 1));
  lexems.push_back({TokenType::STRING, value, line});
}

bool Lexer::isValidIdentifiter(char c) {
        return isalnum(c) || c== '_';
    }
