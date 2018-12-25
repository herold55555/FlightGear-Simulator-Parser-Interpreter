//
// Created by herold55 on 12/12/18.
//

#ifndef EX3T_DATAREADERSERVER_H
#define EX3T_DATAREADERSERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <vector>
#include <map>
#include <mutex>

using namespace std;
class DataReaderServer {
    vector<string> insertOrder;
    map<string, double>* symbolTable;
    map<string, string>* bindM;
    int newsockfd;
public :
    DataReaderServer(map<string, double>* symbolTable, map<string, string>* bind);
    int open(vector<string> vectString);
    static void receiveValue(int socketfd, vector<string> insertO, map<string, double>* symbolTable, map<string, string>* bindMap);
    vector<string> split(string line, char character);
};
#endif //EX3T_DATAREADERSERVER_H
