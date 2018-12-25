//
// Created by sheina on 12/12/18.
//

#include <iostream>
#include "Mult.h"


double Mult::calculate() {
    return this->left->calculate() * this->right->calculate();
}

Mult::Mult(Expression* expression, Expression* expression1) { this->left=expression; this->right=expression1;}
