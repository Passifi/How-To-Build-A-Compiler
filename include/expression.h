#include "../include/lexer.h"

template <typename T> class Terminal {
  T value;
};

struct Nonterminal {
  std::vector<Nonterminal> others;
};

struct Expression {
  int value;
  std::vector<Expression> expressions;
};
struct Grouping {

  TokenType right = TokenType::RIGHT_PAREN;
  TokenType left = TokenType::LEFT_PAREN;
  std::vector<Expression> expressions;
};
struct Statement {
  // contains return and an Expression
  TokenType right = TokenType::SEMICOLON;
  Expression expr;
};
struct Function {
  TokenType returnValue = TokenType::INT;
  std::string identifier;
  Grouping params;
  TokenType open = TokenType::LEFT_BRACKET;
  std::vector<Statement> statements;
  TokenType closing = TokenType::RIGHT_BRACKET;
};

struct Program {
  std::vector<Expression> expressions; 
  std::vector<Function> functions;
};

class Grammar {
public:
  std::vector<TokenType> syntax;

  Grammar(std::vector<TokenType> &syntax) : syntax(syntax) {}

  bool evaluate(std::vector<Token> sentence) {

    for (int i = 0; i < syntax.size(); i++) {

      if (sentence[i].getToken() != syntax[i]) {
        return false;
      }
    }
  }
};



class Parser {
  void function();
  void grouping();
  void statement();
  void panic(Token t);
  bool isType(TokenType t) {
    static std::array<TokenType,5> types = {
      TokenType::INT,
      TokenType::FLOAT,
      TokenType::STRING,
      TokenType::DOUBLE,
      TokenType::CHAR,

    };
    for(auto& type: types) {
      if(t == type) {
        return true;
      }
    }
    return false;
  }
  void parse(std::vector<Token> tokens) {
    
    for(auto& t : tokens ) {
        switch(t.getToken()) {
            default:
              if(isType(t.getToken())) {
                function();
              } 
              else {
                panic(t); 
              }

        }
    }
  }

  bool evaluate();
};

// grouping ( expression )
// unary => ("-" | "!") expression
// binary expression ooperator expression
// literal
// operator "+" "-" etc
