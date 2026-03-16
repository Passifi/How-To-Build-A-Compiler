#include "../include/parser.h"
#include <algorithm>
#include <memory>

bool check(TokenType type);
void Parser::advance() { this->currentIndex++; }
bool Parser::isAtEnd() { return this->currentIndex >= this->_tokens.size(); }
Token Parser::previous() {
  if (this->currentIndex > 0)
    return this->_tokens[currentIndex - 1];
  else
    return Token(TokenType::NULL_TOKEN);
}
Token consume(TokenType type, std::string message);
Token Parser::peek() {
  if (this->_tokens.size() > currentIndex) {
    return _tokens[currentIndex + 1];
  } else
    return Token(TokenType::TOKEN_EOF);
}
bool Parser::match(const std::vector<Token> &tokens) {
  for (auto &token : tokens) {
    if (token.type == this->_tokens[currentIndex].type) {
      advance();
      return true;
    }
  }
  return false;
}
Token Parser::getCurrent() { return this->_tokens[currentIndex]; }
std::unique_ptr<SyntaxNode> Parser::parse() {

  std::vector<std::unique_ptr<Declaration>> declarations;

  while (peek().type != TokenType::TOKEN_EOF) {
    auto declarationNode = declaration();
    declarations.push_back(std::move(declarationNode));
    advance();
  }
  // return std::make_unique<SyntaxNode>(declarations);
}
std::unique_ptr<Declaration> Parser::declaration() {

  if (match(typeCollection)) {
    if (!check(TokenType::IDENTIFIER)) {
      return nullptr;
    } else {
      advance();

      if (!match({TokenType::ASSIGN})) {
        if (!check(TokenType::SEMICOLON)) {
          return nullptr;
        }
      } else {
        while (
            match({TokenType::NUMBER, TokenType::CHAR, TokenType::SEMICOLON})) {
        }
      }
    }
  }
}
StmtPtr parseifStmt();
StmtPtr parseWhileStmt();
StmtPtr parseforStmt();
StmtPtr statement();
ExprPtr expression();
ExprPtr equality();
ExprPtr comparison();
ExprPtr term();
ExprPtr factor();
ExprPtr unary();
ExprPtr primary();
