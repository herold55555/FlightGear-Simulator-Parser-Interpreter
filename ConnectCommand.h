//
// Created by herold55 on 12/11/18.
//

#ifndef EX3T_CONNECTCOMMAND_H
#define EX3T_CONNECTCOMMAND_H
#include "Command.h"
#include "DataClient.h"
class ConnectCommand : public Command{
    map<string, string>* bindMapName;
    DataClient* dataClient;
public:
    ConnectCommand(map<string, string>* bindMapName) {
        this->bindMapName = bindMapName;
        dataClient = new DataClient(this->bindMapName);
    }
    void doCommand(vector<string> vectString);
    void set(string str);
    ~ConnectCommand() {
        delete this->dataClient;
    }
};
#endif //EX3T_CONNECTCOMMAND_H
