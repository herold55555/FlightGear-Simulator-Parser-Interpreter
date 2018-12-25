//
// Created by herold55 on 12/23/18.
//

#ifndef EXE3_ENTERCCOMMAND_H
#define EXE3_ENTERCCOMMAND_H


#include "Command.h"

class EnterCCommand : public Command{
public:
    void doCommand(vector<string> vect);
    void set(string str);
};


#endif //EXE3_ENTERCCOMMAND_H
