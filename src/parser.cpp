#include "../include/parser.h"

std::vector<std::unique_ptr<Expr>>
Parser::parseTokens(std::vector<Token> tokens) {
  std::unique_ptr<Expr> currentExpr;
  for (auto it = tokens.begin(); it != tokens.end(); it++) {

    switch (it->getToken()) {
    case TokenType::LEFT_BRACKET:

      currentExpr = std::make_unique<Grouping>();
    }
  }

  return this->tokenList;
}

std::unique_ptr<Expr> getExpr(int index, std::vector<Token> tokens,
                              std::unique_ptr<Expr> &lastNode) {
  for (int i = index; i < tokens.size(); i++) {
    switch (tokens[i].getToken()) {
    case TokenType::LEFT_BRACKET: {
      auto expr = std::make_unique<Grouping>();
      expr->expr = getExpr(index + 1, tokens, lastNode);
      return expr;
      break;
    }
    case TokenType::MINUS: {
      auto expr = std::make_unique<Unary>(tokens[i]);
      return expr;
    }
    case TokenType::ADD_ASSIGN: {
      auto expr = std::make_unique<Binary>(tokens[i]);
      expr.get()->left = std::move(lastNode);
      expr.get()->right = getExpr(index + 1, tokens, lastNode);
      return expr;
    }
    default:
      return nullptr;
    }
  }
}
