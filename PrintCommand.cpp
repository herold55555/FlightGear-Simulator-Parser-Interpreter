//
// Created by herold55 on 12/17/18.
//

#include <iostream>
#include "PrintCommand.h"

void PrintCommand :: doCommand(vector<string> vectString) {
    int i;
    for(i=0; i<vectString.size()-1; i++) {
        if (this->symbolTable->count(vectString.at(i))) {
            cout<<this->symbolTable->find(vectString.at(i))->second;
        }
        else {
            cout<<vectString.at(0);
        }
    }
    for(map<string, double>::const_iterator it = symbolTable->begin();
        it != symbolTable->end(); ++it)
    {
        std::cout << "symbolTable: " << it->first << " " << it->second << "\n";
    }
    i++;
    i = vectString.size() -1;
    if(this->symbolTable->count(vectString.at(i))) {
        cout<<this->symbolTable->find(vectString.at(i))->second<<endl;
    }
    else {
        cout<<vectString.at(0)<<endl;
    }
}

void PrintCommand :: set(string str) {
    return;
}
