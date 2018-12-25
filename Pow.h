//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_POW_H
#define EXE3_POW_H


#include "BinaryExpression.h"

class Pow : public BinaryExpression{
    Expression* left;
    Expression* right;
public:
    virtual double calculate();

    Pow(Expression* expression, Expression* expression1);
};


#endif //EXE3_POW_H
