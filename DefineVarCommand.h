//
// Created by herold55 on 12/11/18.
//

#ifndef EX3T_DEFINEVARCOMMAND_H
#define EX3T_DEFINEVARCOMMAND_H
#include "Command.h"
class DefineVarCommand : public Command {
    map<string, string>* bindMap;
    map<string, double>* symbolTable;
    map<string, string>* bindMapName;
public:
    DefineVarCommand(map<string, string>* bindM, map<string, double>* symbolTab, map<string, string>* bindMapName) {
        this->bindMap = bindM;
        this->symbolTable = symbolTab;
        this->bindMapName = bindMapName;
    }
    void doCommand(vector<string> vectString);
    bool is_number(const string& s);
    void set(string str);
    ~DefineVarCommand() {
    }
};
#endif //EX3T_DEFINEVARCOMMAND_H
