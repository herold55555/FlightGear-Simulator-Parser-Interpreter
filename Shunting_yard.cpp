//
// Created by sheina on 12/12/18.
//

#include "Shunting_yard.h"

#include <cstdio>
#include <vector>
#include "Shunting_yard.h"


Shunting_yard::Shunting_yard(std::string str)
{
    this->infix = str;
    op.insert( pair<char, pair<int, bool> >('+', pair<int, bool>(2,  0) ));
    op.insert( pair<char, pair<int, bool> >('-', pair<int, bool>(2,  0) ));
    op.insert( pair<char, pair<int, bool> >('*', pair<int, bool>(3,  0) ));
    op.insert( pair<char, pair<int, bool> >('/', pair<int, bool>(3,  0) ));
    op.insert( pair<char, pair<int, bool> >('^', pair<int, bool>(4,  1) ));

}

bool Shunting_yard::isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void Shunting_yard::convert()
{
    stack<char> operators;
    std::vector<char> a;
    a.reserve(infix.size());
    for(char c : infix)
        a.push_back(c);
    int i = 0;
    while (i < a.size())
    {
        if (isdigit(a.at(i)) || a.at(i)=='.')
        {
            postfix += a.at(i);
            if(i < a.size()-1 && !isdigit(a.at(i+1)) && a.at(i+1) != '.') {
                postfix += " ";
            }
            if(i == a.size()-1) { postfix += " "; }
        }
        else if (isoperator(a.at(i)))
        {
            if(a.at(i) == '-' && (i==0 || !isdigit(a.at(i-1)))) {
                postfix += a.at(i);
            }
            else {
                char o1 = a.at(i);
                bool offset = 0;
                if (!this->op[o1].second)
                    offset = 1;
                if (!operators.empty()) {
                    char top = operators.top();
                    while (isoperator(top)) {
                        if (op[o1].first < op[top].first + offset) {
                            postfix += top;
                            postfix += " ";
                            operators.pop();
                        } else break;
                        if (operators.empty())
                            break;
                        else top = operators.top();
                    }
                }
                operators.push(o1);
            }
        }
        else if (a.at(i) == '(')
        {
            operators.push(a.at(i));
        }
        else if (a.at(i) == ')')
        {
            while (operators.top() != '(')
            {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            operators.pop();
        }
        i++;
    }
    if (!operators.empty())
    {
        int size = operators.size();
        for (int i = 0; i < size; i++)
        {
            postfix += operators.top();
            postfix += " ";
            operators.pop();
        }
    }
}