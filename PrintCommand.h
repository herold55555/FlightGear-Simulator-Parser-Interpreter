//
// Created by herold55 on 12/17/18.
//

#ifndef EX3PROJECT_PRINTCOMMAND_H
#define EX3PROJECT_PRINTCOMMAND_H
#include "Command.h"
using namespace std;
class PrintCommand : public Command {
map<string, double>* symbolTable;
public:
    PrintCommand(map<string, double>* s) {
        symbolTable = s;
    }
    void doCommand(vector<string> vectString);
    void set(string str);
    ~PrintCommand() {
    }
};
#endif //EX3PROJECT_PRINTCOMMAND_H
