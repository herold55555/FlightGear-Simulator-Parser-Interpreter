//
// Created by herold55 on 12/11/18.
//

#ifndef EX3T_OPENSERVERCOMMAND_H
#define EX3T_OPENSERVERCOMMAND_H
#include "Command.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "DataReaderServer.h"
class OpenServerCommand : public Command {
    map<string, double>* symbolTable;
    map<string, string>* bindMap;
public :
    OpenServerCommand(map<string, double>* symbolTab, map<string, string>* bindMap) {
    this->symbolTable = symbolTab;
    this->bindMap = bindMap;
}
    virtual void doCommand(vector<string> vectString);
    void set(string str);
    ~OpenServerCommand() {
    }
};
#endif //EX3T_OPENSERVERCOMMAND_H
