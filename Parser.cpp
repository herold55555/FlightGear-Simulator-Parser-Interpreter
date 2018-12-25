//
// Created by herold55 on 12/11/18.
//
#include <string>
#include <cstdlib>
#include <iostream>
#include "Parser.h"
#include "Solver.h"

vector<string> Parser :: split(string line, char character) {
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


void Parser :: parse(vector<string> vect) {
    int i = 0, k = 0;
    string temp;
    vector<string> search;
    vector<string> tempVect;
    while (i < vect.size()) {
        string exp = getAstringWithSpace(vect.at(i));
        search = split(exp, ' ');
        temp = search.at(0);
        if(temp == "exit") {
            return;
        }
        else if (this->mapCommand.count(temp)) {
            if (temp == "while" || temp == "if") {
                vector<string> block;
                while (search.at(search.size()-1) != "}") {
                    block.push_back(vect.at(i));
                    i++;
                    search = split(vect.at(i), ' ');
                }
                block.push_back(vect.at(i));
                i++;
                this->mapCommand[temp]->doCommand(block);
            }
            else {
                for(int l = 1; l < search.size(); l++) {
                    tempVect.push_back(search.at(l));
                }
                this->mapCommand[temp]->doCommand(tempVect);
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
                /*string t;
                for(k=2; k<search.size(); k++) {
                    t += search.at(k);
                }
                exp = getAstringWithSpace(t);
                v = split(exp, ' ');*/
                for(k = 2; k < search.size(); k++) {
                    temp2 = search.at(k);
                    if(this->symbolTable.count(temp2)) {
                        expr += to_string(this->symbolTable[search.at(k)]);
                    }
                    else {
                        expr += search.at(k);
                    }
                }
                Solver* e = new Solver(expr);
                double res = e->solve()->calculate();
                temp2 = this->bindMapName[temp];
                temp2 += " ";
                temp2 += to_string(res);
                this->connect->set(temp2);
                this->symbolTable[temp] = res;
                i++;
                delete e;
            }
        }
    }
}


map<string, double>* Parser :: getSymbolTable() {
    return &this->symbolTable;
}

map<string, string>* Parser ::getbindMapAdress() {
    return &this->bindMapAdress;
}

map<string, string>* Parser ::getExpressionMap() {
    return &this->bindMapAdress;
}

map<string, Command*>* Parser ::getCommandMap() {
    return &this->mapCommand;
}

string Parser :: getAstringWithSpace(string s) {
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

bool Parser::isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')' || c == '=';
}