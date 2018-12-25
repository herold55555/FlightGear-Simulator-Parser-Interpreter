//
// Created by herold55 on 12/18/18.
//

#ifndef EX3T_LOOPCOMMAND_H
#define EX3T_LOOPCOMMAND_H
#include "Command.h"

class LoopCommand : public Command {
    map<string, double>* symbolTable;
    map<string, Command*>* mapCommand;
    map<string, string>* bindMapName;
public :
    LoopCommand(map<string, double>* symbolTab, map<string, Command*>* mapComm, map<string, string>* bindMapN) {
       this->symbolTable = symbolTab;
       this->mapCommand = mapComm;
       this->bindMapName = bindMapN;
    }
    void doCommand(vector<string> vectString);
    bool checkIfTrue(double varValue, string expression, double value);
    void loopFunction(vector<string> vectString);
    bool isBoolExpression(string s);
    void set(string str);
    vector<string> split(string line, char character);
    string getAstringWithSpace(string s);
    bool isoperator(char c);
    ~LoopCommand() {
    }
};
#endif //EX3PROJECT_LOOPCOMMAND_H
