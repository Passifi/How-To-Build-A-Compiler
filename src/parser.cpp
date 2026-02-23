#include "../include/parser.h"
#include <memory>

std::vector<Token> typeCollection = {
    TokenType::INT_TYPE,    TokenType::CHAR_TYPE, TokenType::FLOAT_TYPE,
    TokenType::DOUBLE_TYPE, TokenType::LONG_TYPE, TokenType::LONGLONG_TYPE,

};

bool Parser::match(const std::vector<Token> &tokens) {
  int temporaryIndex = currentIndex;
  for (auto token : tokens) {
    if (check(token.getToken())) {
      advance();
      return true;
    }
  }
  return false;
}

ExprPtr Parser::parse() {
  std::cout << currentIndex << std::endl;

  return expression();
}

bool Parser::check(TokenType type) {
  return this->_tokens[currentIndex].getToken() == type;
}

void Parser::advance() { currentIndex++; }

ExprPtr Parser::equality() {
  ExprPtr expr = comparison();

  while (match({TokenType::EQUAL, TokenType::NOT_EQUAL})) {
    Token op = previous();
    ExprPtr right = comparison();
    expr = std::make_unique<Binary>(std::move(expr), op, std::move(right));
  }
  return expr;
}
Token Parser::peek() { return _tokens[currentIndex + 1]; }

Token Parser::previous() { return _tokens[currentIndex - 1]; }

ExprPtr Parser::comparison() {
  ExprPtr expr = term();
  while (match({TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS,
                TokenType::LESS_EQUAL})) {
    Token op = previous();
    ExprPtr right = term();
    expr = std::make_unique<Binary>(std::move(expr), op, std::move(right));
  }
  return expr;
}
ExprPtr Parser::term() {
  ExprPtr expr = factor();

  while (match({TokenType::MINUS, TokenType::PLUS})) {
    Token op = previous();
    ExprPtr right = factor();
    expr = std::make_unique<Binary>(std::move(expr), op, std::move(right));
  }
  return expr;
}
ExprPtr Parser::factor() {
  auto expr = unary();
  while (match({TokenType::SLASH, TokenType::STAR})) {
    Token op = previous();
    ExprPtr right = unary();
    expr = std::make_unique<Binary>(std::move(expr), op, std::move(right));
  }

  return expr;
}
ExprPtr Parser::unary() {
  if (match({TokenType::BANG, TokenType::MINUS})) {
    Token op = previous();
    auto right = unary();
    return std::make_unique<Unary>(op, std::move(right));
  }

  return primary();
}

bool Parser::isAtEnd() { return currentIndex >= _tokens.size(); }
ExprPtr Parser::primary() {

  if (match(typeCollection)) {
    auto value = previous();
    return std::make_unique<Literal>(value.getLiteralValue());
  }
  if (match({TokenType::LEFT_PAREN})) {
    auto expr = expression();
    consume(TokenType::RIGHT_PAREN, "Expect \")\" after expressionl");
    return std::make_unique<Grouping>(std::move(expr));
  }
  auto res = std::make_unique<Literal>("Unkown");
  return res;
};

ExprPtr Parser::expression() { return equality(); }

Token Parser::consume(TokenType type, std::string message) {

  if (check(type)) {
    advance();
    return type;
  }
  return TokenType::UNKOWN;
}
