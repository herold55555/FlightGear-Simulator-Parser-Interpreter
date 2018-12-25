//
// Created by herold55 on 12/18/18.
//

#include <iostream>
#include "LoopCommand.h"
#include "Solver.h"
#include "Parser.h"

void LoopCommand ::doCommand(vector<string> vectString) {
   // check si c'est un if ou un while et appeler loopFunction
   Parser inter;
   vector<string> parser = inter.split(vectString.at(0), ' ');
   string exp1, exp2, boolExp;
   int i=1;
   while(!isBoolExpression(parser.at(i))) {
       if(this->symbolTable->count(parser.at(i))) {
           exp1 += to_string(this->symbolTable->find(parser.at(i))->second);
       }
       else {
           exp1 += parser.at(i);
       }
       i++;
   }
   boolExp = parser.at(i);
   i++;
    while(i<parser.size()) {
        if(this->symbolTable->count(parser.at(i))) {
            exp2 += to_string(this->symbolTable->find(parser.at(i))->second);
        }
        else {
            exp2 += parser.at(i);
        }
        i++;
    }
    Solver s1(exp1);
    Solver s2(exp2);
   if (parser.at(0) == "if") {
       if (checkIfTrue(s1.solve()->calculate(), boolExp, s2.solve()->calculate())) {
           vectString.erase(vectString.begin());
           this->loopFunction(vectString);
       }
   }
   else if (parser.at(0) == "while") {
       while (checkIfTrue(s1.solve()->calculate(), boolExp, s2.solve()->calculate())) {
           vectString.erase(vectString.begin());
           this->loopFunction(vectString);
           exp1 = "";
           exp2 = "";
           i=1;
           while(!isBoolExpression(parser.at(i))) {
               if(this->symbolTable->count(parser.at(i))) {
                   exp1 += to_string(this->symbolTable->find(parser.at(i))->second);
               }
               else {
                   exp1 += parser.at(i);
               }
               i++;
           }
           boolExp = parser.at(i);
           i++;
           while(i<parser.size()) {
               if(this->symbolTable->count(parser.at(i))) {
                   exp2 += to_string(this->symbolTable->find(parser.at(i))->second);
               }
               else {
                   exp2 += parser.at(i);
               }
               i++;
           }
           s1 = exp1;
           s2 = exp2;
       }
   }
   else {
       throw "BAD COMMAND";
   }
}

bool LoopCommand :: checkIfTrue(double val1, string expression, double val2) {
    if (expression == "==")
        return val1 == val2;
    if (expression == ">=")
        return val1 >= val2;
    if (expression == "<=")
        return val1 <= val2;
    if (expression == ">")
        return val1 > val2;
    if (expression == "<")
        return val1 < val2;
    if (expression == "!=")
        return val1 != val2;
    return false;
}

void LoopCommand :: loopFunction(vector<string> vectString) {
    int i = 0, k = 0;
    string temp;
    vector<string> search;
    vector<string> tempVect;
    while (i < vectString.size()) {
        string exp = getAstringWithSpace(vectString.at(i));
        search = split(exp, ' ');
        temp = search.at(0);
        if (this->mapCommand->count(temp)) {
            if (temp == "while" || temp == "if") {
                vector<string> block;
                while (search.at(search.size()-1) != "}") {
                    block.push_back(vectString.at(i));
                    i++;
                    search = split(vectString.at(i), ' ');
                }
                block.push_back(vectString.at(i));
                i++;
                this->mapCommand->find(temp)->second->doCommand(block);
            }
            else {
                for(int l = 1; l < search.size(); l++) {
                    tempVect.push_back(search.at(l));
                }
                this->mapCommand->find(temp)->second->doCommand(tempVect);
                tempVect.clear();
                i++;
            }
        }
        else {
            string temp2, exp, expr;
            vector<string> v;
            temp = search.at(0);
            if(temp == "}" || temp == "{") {i++;}
            else {
                for(k = 2; k < search.size(); k++) {
                    temp2 = search.at(k);
                    if(this->symbolTable->count(temp2)) {
                        expr += to_string(this->symbolTable->find(search.at(k))->second);
                    }
                    else {
                        expr += search.at(k);
                    }
                }
                Solver* e = new Solver(expr);
                double res = e->solve()->calculate();
                temp2 = this->bindMapName->find(temp)->second;
                temp2 += " ";
                temp2 += to_string(res);
                this->mapCommand->find("connect")->second->set(temp2);
                this->symbolTable->find(temp)->second = res;
                i++;
                delete e;
            }
        }
    }
}

bool LoopCommand :: isBoolExpression(string s) {
    return (s == "==" || s == "<" || s == ">" || s == "=<" || s == "=>" || s == "!=");
}

void LoopCommand :: set(string str) {
    return;
}

string LoopCommand :: getAstringWithSpace(string s) {
    string str;
    std::vector<char> a;
    a.reserve(s.size());
    for(char c : s)
        a.push_back(c);
    int i = 0;
    while (i < a.size()) {
        if (isdigit(a.at(i))) {
            str += a.at(i);
            if (i < a.size() - 1 && !isdigit(a.at(i + 1)) && a.at(i+1) != '.' && a.at(i+1) != ' ') {
                str += " ";
            }
            if (i == a.size() - 1) { str += " "; }
        }
        else if (isoperator(a.at(i))) {
            str += a.at(i);
            if(i < a.size() - 1 && a.at(i+1) != ' ') {str += " ";}
        }
        else if(a.at(i) == '"') {
            if(a.at(i-1) != ' ') { str += " ";}
            str += a.at(i);
            i++;
            while (a.at(i) != '"') {
                str += a.at(i);
                i++;
            }
            str += '"';
            str += " ";
        }
        else if (a.at(i) == ' ') {
            str += a.at(i);
        }
        else {
            str += a.at(i);
            if (i < a.size() - 1 && isoperator(a.at(i+1)) && a.at(i+1) != ' ') {
                str += " ";
            }
        }
        i++;
    }
    return str;
}

bool LoopCommand :: isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')' || c == '=';
}

vector<string> LoopCommand :: split(string line, char character) {
    stringstream ss(line);
    vector<string> result;
    while( ss.good() )
    {
        string substr;
        getline( ss, substr,character);
        result.push_back(substr);
    }
    return result;
}