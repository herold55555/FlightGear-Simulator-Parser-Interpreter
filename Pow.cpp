//
// Created by sheina on 12/12/18.
//


#include <cmath>
#include "Pow.h"

double Pow::calculate() {return pow(this->left->calculate(),this->right->calculate());}

Pow::Pow(Expression* expression, Expression* expression1) {this->left = expression; this->right = expression1;}
