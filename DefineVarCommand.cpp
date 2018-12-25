//
// Created by herold55 on 12/11/18.
//
#include "DefineVarCommand.h"
#include "Solver.h"

void DefineVarCommand ::doCommand(vector<string> vectString) {
    string myString;
    string temp2 = "";
    if (vectString.size() < 3)
        throw "WRONG NUMBER OF ARGUMENTS";
    if (vectString.at(2) == "bind") {
        if(this->bindMapName->count(vectString.at(3))) {
            string path = this->bindMapName->find(vectString.at(3))->second;
            this->bindMap->insert(pair<string, string>(path, vectString.at(0)));
            this->bindMapName->insert(pair<string, string>(vectString.at(0), path));
            double val =  this->symbolTable->find(vectString.at(3))->second;
            this->symbolTable->insert(pair<string, double>(vectString.at(0), val));
        }
       else {
            string temp(vectString.at(3), 1);
            myString = temp.substr(0, temp.size() - 1);
            this->bindMap->insert(pair<string, string>(myString, vectString.at(0)));
            this->bindMapName->insert(pair<string, string>(vectString.at(0), myString));
            this->symbolTable->insert(pair<string, double>(vectString.at(0), 0));
       }
    }
    else {
        int k;
        string expr;
        for(k=2; k<vectString.size(); k++) {
            if(this->symbolTable->count(vectString.at(k))) {
                expr += to_string(this->symbolTable->find(vectString.at(k))->second);
            }

            else {
                expr += vectString.at(k);
            }
        }
        Solver* e = new Solver(expr);
        this->symbolTable->insert(pair<string, double>(vectString.at(0), e->solve()->calculate()));
        delete e;
    }
}


bool DefineVarCommand :: is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void DefineVarCommand ::set(string str) {
    return;
}