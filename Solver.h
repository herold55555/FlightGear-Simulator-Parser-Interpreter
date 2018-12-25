//
// Created by sheina on 12/12/18.
//

#ifndef EXE3_SOLVER_H
#define EXE3_SOLVER_H


#include <string>
#include <vector>
#include "Expression.h"

using namespace std;

class Solver {
private:
    std::string postfix;
    bool isOperator(string);
    vector<Expression*> vectEXp;
public:
    Expression* result;
    Solver(string str);
    vector<string> split(string line, char c);
    Expression* solve();
    string getPostfix();
    ~Solver() {
        for (int i = 0; i < this->vectEXp.size(); i++) {
            delete this->vectEXp.at(i);
        }
    }
};



#endif //EXE3_SOLVER_H
