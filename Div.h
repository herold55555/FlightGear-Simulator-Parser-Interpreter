//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_DIV_H
#define EXE3_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression{
    Expression* left;
    Expression* right;

public:
    virtual double calculate();

    Div(Expression* expression, Expression* expression1);
};



#endif //EXE3_DIV_H
