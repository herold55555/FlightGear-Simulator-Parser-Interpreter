//
// Created by herold55 on 12/17/18.
//

#ifndef EX3PROJECT_DATACLIENT_H
#define EX3PROJECT_DATACLIENT_H

#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <map>

using namespace std;
class DataClient {
    int socketConnect;
    map<string, string>* bindMapName;
public :
    DataClient(map<string, string>* bindMapName) {
    this->bindMapName = bindMapName;
}
    int connect(vector<string> vect);
    void set(string str);
    void get(string str);
};
#endif //EX3PROJECT_DATACLIENT_H
