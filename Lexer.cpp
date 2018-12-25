//
// Created by herold55 on 12/19/18.
//

#include "Lexer.h"
vector<string> Lexer :: lexer(const char *file) {
    ifstream read;
    vector<string> information;
    read.open(file);
    string line;
    if (!read.good())
        throw "ERROR OPENING THE FILE";
    while (getline(read, line)) {
        information.push_back(line);
    }
    read.close();
    return information;
}