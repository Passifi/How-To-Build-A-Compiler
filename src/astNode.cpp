#include "../include/astNode.h"

SyntaxNode::SyntaxNode() {}

Declaration::Declaration(TokenType type, std::string id)
    : type(type), identifier(id) {}
