//
// Created by sheina on 12/12/18.
//

#include <iostream>
#include "Num.h"

Num ::Num(string n) {this->number = stoi(n);}
double Num ::calculate() {
    return number;
}