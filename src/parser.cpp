#include "../include/parser.h"
#include <memory>

std::vector<Token> typeCollection = {
    TokenType::INT_TYPE,    TokenType::CHAR_TYPE, TokenType::FLOAT_TYPE,
    TokenType::DOUBLE_TYPE, TokenType::LONG_TYPE, TokenType::LONGLONG_TYPE,
};

ExprPtr Parser::parse() {
  switch (getToken().getToken()) {

  case TokenType::IF:
    advance();
    return parseifStmt();

  default:
    return expression();
  }
}

ExprPtr Parser::statement() { return nullptr; }

ExprPtr Parser::expression() { return equality(); }

ExprPtr Parser::equality() {
  ExprPtr expr = comparison();
  while (match({TokenType::EQUAL, TokenType::NOT_EQUAL})) {
    Token op = previous();
    ExprPtr right = comparison();
    expr = std::make_unique<Binary>(std::move(expr), op, std::move(right));
  }
  return expr;
}

ExprPtr Parser::parseifStmt() {
  std::unique_ptr<IfStmt> result;

  if (!check(TokenType::LEFT_PAREN)) {
    // pointer with error attached
  } else {
    result.get()->condition = expression();
    consume(TokenType::RIGHT_PAREN, "Expected closing )");
    result.get()->block = parse();
    if (check(TokenType::ELSE)) {

      result.get()->elseBlock = parse();
    }
  }
}

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

  while (match({TokenType::MINUS, TokenType::PLUS, TokenType::COMMA,
                TokenType::ASSIGN})) {
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
  if (match({TokenType::LEFT_BRACKET})) {
    auto expr = expression();
    consume(TokenType::RIGHT_BRACKET, "Expect ] after expression [");
    return std::make_unique<Grouping>(std::move(expr));
  }
  if (match({TokenType::LEFT_CURLY_BRACKET})) {
    auto expr = expression();
    consume(TokenType::RIGHT_CURLY_BRACKET, "Expect } after expression {");
    return std::make_unique<Grouping>(std::move(expr));
  }
  auto value = _tokens[currentIndex];
  auto res = std::make_unique<Literal>(value.getLiteralValue());
  advance();
  return res;
};

bool Parser::match(const std::vector<Token> &tokens) {
  int temporaryIndex = currentIndex;
  for (auto token : tokens) {
    if (check(token.getToken())) {
      advance();
      return true;
    }
  }
  currentIndex = temporaryIndex;
  return false;
}

Token Parser::getToken() { return this->_tokens[currentIndex]; }
bool Parser::check(TokenType type) {
  return this->_tokens[currentIndex].getToken() == type;
}

bool Parser::isAtEnd() { return (size_t)currentIndex >= _tokens.size(); }

void Parser::advance() { currentIndex++; }

Token Parser::peek() { return _tokens[currentIndex + 1]; }

Token Parser::previous() { return _tokens[currentIndex - 1]; }

Token Parser::consume(TokenType type, [[maybe_unused]] std::string message) {
  if (check(type)) {
    advance();
    return type;
  }
  return TokenType::UNKOWN;
}
