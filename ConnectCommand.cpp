//
// Created by herold55 on 12/11/18.
//
#include "ConnectCommand.h"

void ConnectCommand :: doCommand(vector<string> vectString) {
    this->dataClient->connect(vectString);
}
 void ConnectCommand ::set(string str) {
    string str2;
    this->dataClient->set(str);
 }