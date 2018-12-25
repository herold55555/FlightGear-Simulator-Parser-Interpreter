//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_SHUNTING_YARD_H
#define EXE3_SHUNTING_YARD_H


#include <string>
#include <map>
#include <stack>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Shunting_yard {
private:
    string infix;
    //Operators features(precedence, right associative)
    map<char, pair<int, bool> > op;

    bool isoperator(char);
public:
    Shunting_yard(string);
    void convert();
    std::string postfix;
};


#endif //EXE3_SHUNTING_YARD_H
