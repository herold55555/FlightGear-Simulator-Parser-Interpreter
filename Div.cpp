//
// Created by sheina on 12/12/18.
//

#include "Div.h"


double Div::calculate() {return this->left->calculate() / this->right->calculate();}

Div::Div(Expression* expression, Expression* expression1) {this->left = expression; this->right = expression1;}
