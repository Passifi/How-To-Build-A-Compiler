#pragma once 
#include "../include/token.h"
#include  <vector>
#include <variant>


struct Expression {
};

struct Literal :public Expression{
    std::string value;
};


struct SyntaxOperator{

};
struct Unary :public Expression {
    Expression expression;
    SyntaxOperator syntaxOperator;
    public: 
        void evaluate();
}; 

struct Binary : public Expression{
    Expression left; 
    Expression right; 
    SyntaxOperator binaryOperator;
};

    


class SyntaxTreeNode {
    std::vector<SyntaxTreeNode*> leaves;
    std::variant<Expression> value;
    public:
    std::vector<SyntaxTreeNode*> getNodes();
};