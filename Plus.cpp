//
// Created by sheina on 12/12/18.
//

#include "Plus.h"


double Plus::calculate() {return this->left->calculate() + this->right->calculate();}

Plus::Plus(Expression* expression, Expression* expression1) {this->left = expression; this->right = expression1;}
