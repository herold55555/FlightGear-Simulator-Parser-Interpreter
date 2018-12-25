//
// Created by herold55 on 12/11/18.
//

#ifndef EX3T_PARSER_H
#define EX3T_PARSER_H
#include "string"
#include "vector"
#include "Command.h"
#include "OpenServerCommand.h"
#include "DefineVarCommand.h"
#include "ConnectCommand.h"
#include "PrintCommand.h"
#include "LoopCommand.h"
#include "EnterCCommand.h"
#include "Sleep.h"
#include <fstream>
#include <sstream>
using namespace std;
class Parser {
    map<string, Command*> mapCommand;
    map<string, double> symbolTable;
    map<string, string> bindMapAdress;
    map<string, string> bindMapName;
    Command* open;
    Command* connect;
    Command* defineVar;
    Command* print;
    Command* whileCommand;
    Command* ifCommand;
    Command* enterC;
    Command* sleep;
public :
    Parser() {
        this->open = new OpenServerCommand(&this->symbolTable, &this->bindMapAdress);
        this->connect = new ConnectCommand(&this->bindMapName);
        this->defineVar = new DefineVarCommand(&this->bindMapAdress, &this->symbolTable, &this->bindMapName);
        this->print = new PrintCommand(&this->symbolTable);
        this->whileCommand = new LoopCommand(&this->symbolTable, &this->mapCommand, &this->bindMapName);
        this->ifCommand = new LoopCommand(&this->symbolTable, &this->mapCommand, &this->bindMapName);
        this->enterC = new EnterCCommand();
        this->sleep = new Sleep();
        this->mapCommand.insert(pair<string, Command*>("openDataServer", this->open));
        this->mapCommand.insert(pair<string, Command*>("connect", this->connect));
        this->mapCommand.insert(pair<string, Command*>("var", this->defineVar));
        this->mapCommand.insert(pair<string, Command*>("print", this->print));
        this->mapCommand.insert(pair<string, Command*>("if", this->ifCommand));
        this->mapCommand.insert(pair<string, Command*>("while", this->whileCommand));
        this->mapCommand.insert(pair<string, Command*>("enterC", this->enterC));
        this->mapCommand.insert(pair<string, Command*>("sleep", this->sleep));
    }
    vector<string> split(string line, char character);
    void parse(vector<string> vect);
    map<string, string>* getbindMapAdress();
    map<string, string>* getExpressionMap();
    map<string, double>* getSymbolTable();
    map<string, Command*>* getCommandMap();
    string getAstringWithSpace(string s);
    bool isoperator(char c);
    ~Parser() {
        delete this->open;
        delete this->connect;
        delete this->defineVar;
        delete this->print;
        delete this->whileCommand;
        delete this->ifCommand;
        delete this->enterC;
        delete this->sleep;
    }
};
#endif //EX3T_PARSER_H