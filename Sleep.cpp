//
// Created by herold55 on 12/25/18.
//

#include <unistd.h>
#include "Sleep.h"

void Sleep::doCommand(vector<string> vect) {
    sleep(stoi(vect.at(0))/1000);
}

void Sleep ::set(string str) {
    return;
}