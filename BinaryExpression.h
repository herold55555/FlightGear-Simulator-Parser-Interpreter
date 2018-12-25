//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_BINARYEXPRESSION_H
#define EXE3_BINARYEXPRESSION_H


#include "Expression.h"

class BinaryExpression : public Expression{
    Expression* left;
    Expression* right;

public:
    BinaryExpression(Expression* l, Expression* r);
    BinaryExpression();
    virtual double calculate();

};

#endif //EXE3_BINARYEXPRESSION_H
