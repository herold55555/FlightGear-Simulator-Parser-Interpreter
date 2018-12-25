//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_MINUS_H
#define EXE3_MINUS_H

#include "Expression.h"
#include "BinaryExpression.h"

class Minus : public  BinaryExpression{

    Expression* left;
    Expression* right;
public:
    virtual double calculate();

    Minus(Expression* l, Expression* r);
};


#endif //EXE3_MINUS_H
