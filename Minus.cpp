//
// Created by sheina on 12/12/18.
//

#include "Minus.h"


double Minus::calculate() {return this->left->calculate() - this->right->calculate();}

Minus::Minus(Expression* l, Expression* r) {this->left = l; this->right = r;}
