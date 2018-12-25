//
// Created by sheina on 12/12/18.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression* l, Expression* r) { this->left = l, this->right = r;}
BinaryExpression::BinaryExpression() {}
double BinaryExpression::calculate() {}
