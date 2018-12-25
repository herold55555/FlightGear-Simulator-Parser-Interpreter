//
// Created by herold55 on 12/11/18.
//
#include <strings.h>
#include "OpenServerCommand.h"

void OpenServerCommand :: doCommand(vector<string> vectString) {
    DataReaderServer data(this->symbolTable, this->bindMap);
    data.open(vectString);
}

void OpenServerCommand :: set(string str) {
    return;
}