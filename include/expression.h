#include "../include/lexer.h"

template <typename T> class Terminal {
  T value;
};

class Nonterminal {
  std::vector<Nonterminal> others;
};

class Expression {
  int value;
  std::vector<Expression> expressions;
};

class Statement {
  // contains return and an Expression
  TokenType left = TokenType::RETURN;
  TokenType right = TokenType::SEMICOLON;
  Expression expr;
};

class Function {
  TokenType returnValue = TokenType::INT;
  std::string identifier;
  TokenType open = TokenType::LEFT_BRACKET;
  Statement statement;
  TokenType closing = TokenType::RIGHT_BRACKET;
};

class Program {
  Function function;
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

  void parse(std::vector<Token> tokens) {}

  bool evaluate();
};

// grouping ( expression )
// unary => ("-" | "!") expression
// binary expression ooperator expression
// literal
// operator "+" "-" etc
