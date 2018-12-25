//
// Created by sheina on 12/12/18.
//


#include <cstdio>
#include <cmath>
#include "Solver.h"
#include "Shunting_yard.h"
#include "Plus.h"
#include "Num.h"
#include "Minus.h"
#include "Div.h"
#include "Mult.h"
#include "Pow.h"

Solver::Solver(string str)
{
    Shunting_yard exp(str);
    exp.convert();
    this->postfix = exp.postfix;
}

string Solver::getPostfix() {return postfix;}
vector<string> Solver :: split(string line, char c) {
    stringstream ss( line );
    vector<string> result;
    while( ss.good() )
    {
        string substr;
        getline( ss, substr, c );
        result.push_back( substr );
    }
    return result;
}

bool Solver::isOperator(string c)
{
    return c == "+" || c == "-" || c == "*" || c == "/" || c == "^";
}


Expression* Solver::solve()
{
    std::stack<Expression*> exp;
    vector<string> v = split(postfix, ' ');
    for (int i=0; i<v.size()-1; i++)
    {
        if (isOperator(v.at(i)))
        {
            Expression* e2 = exp.top();
            exp.pop();
            Expression* e1;
            if (!exp.empty())
            {
                e1 = exp.top();
                exp.pop();
            }
            if (v.at(i) == "+") {
                Expression* p = new Plus(e1, e2);
                this->vectEXp.push_back(p);
                exp.push(p);
            }
            else if(v.at(i) == "-") {
                Expression* m = new Minus(e1, e2);
                this->vectEXp.push_back(m);
                exp.push(m);
            }
            else if (v.at(i) == "*")
            {
                Expression* mu = new Mult(e1, e2);
                this->vectEXp.push_back(mu);
                exp.push(mu);
            }
            else if (v.at(i) == "/") {
                Expression* d = new Div(e1, e2);
                this->vectEXp.push_back(d);
                exp.push(d);
            }
            else if (v.at(i) == "^") {
                Expression* pow = new Pow(e1, e2);
                this->vectEXp.push_back(pow);
                exp.push(pow);
            }

        }
        else {
            Expression* num = new Num(v.at(i));
            this->vectEXp.push_back(num);
            exp.push(num);
        }
    }
    result = exp.top();
    return result;
}