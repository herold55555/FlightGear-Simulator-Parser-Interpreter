//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_NUM_H
#define EXE3_NUM_H

#include <string>
#include "Expression.h"
using namespace std;

class Num : public Expression{
    double number;

public:
    Num(string n);
    virtual double calculate();

};


#endif //EXE3_NUM_H
