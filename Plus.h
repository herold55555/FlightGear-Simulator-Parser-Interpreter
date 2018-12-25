//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_PLUS_H
#define EXE3_PLUS_H


#include <string>
#include "Expression.h"
#include "BinaryExpression.h"

using namespace std;

class Plus : public BinaryExpression{
    Expression* left;
    Expression* right;
public:
    virtual double calculate();

    Plus(Expression* expression, Expression* expression1);
};


#endif //EXE3_PLUS_H
