//
// Created by herold55 on 12/10/18.
//

#ifndef EX3T_COMMAND_H
#define EX3T_COMMAND_H
#include "string"
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
class Command {

public :
    virtual void doCommand(vector<string> vectString) = 0;
    virtual void set(string str) = 0;
    virtual ~Command(){}
};

#endif //EX3T_COMMAND_H