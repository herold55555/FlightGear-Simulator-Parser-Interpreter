//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_MULT_H
#define EXE3_MULT_H


#include "BinaryExpression.h"

class Mult : public BinaryExpression{
    Expression* left;
    Expression* right;
public:
    virtual double calculate();

    Mult(Expression* expression, Expression* expression1);
};


#endif //EXE3_MULT_H
