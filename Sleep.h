//
// Created by herold55 on 12/25/18.
//

#ifndef EXE3_SLEEP_H
#define EXE3_SLEEP_H


#include "Command.h"

class Sleep : public Command{
    void doCommand(vector<string> vect);
    void set(string str);
};


#endif //EXE3_SLEEP_H
