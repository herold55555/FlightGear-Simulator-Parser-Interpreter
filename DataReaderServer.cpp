//
// Created by herold55 on 12/12/18.
//

#include <strings.h>
#include <iostream>
#include <sstream>
#include <thread>
#include "DataReaderServer.h"

DataReaderServer::DataReaderServer(map<string, double>* symbolTable, map<string, string>* bind) {
    this->symbolTable = symbolTable;
    this->bindM = bind;
    insertOrder.emplace_back("/instrumentation/airspeed-indicator/indicated-speed-kt");
    insertOrder.emplace_back("/instrumentation/altimeter/indicated-altitude-ft");
    insertOrder.emplace_back("/instrumentation/altimeter/pressure-alt-ft");
    insertOrder.emplace_back("/instrumentation/attitude-indicator/indicated-pitch-deg");
    insertOrder.emplace_back("/instrumentation/attitude-indicator/indicated-roll-deg");
    insertOrder.emplace_back("/instrumentation/attitude-indicator/internal-pitch-deg");
    insertOrder.emplace_back("/instrumentation/attitude-indicator/internal-roll-deg");
    insertOrder.emplace_back("/instrumentation/encoder/indicated-altitude-ft");
    insertOrder.emplace_back("instrumentation/encoder/pressure-alt-ft");
    insertOrder.emplace_back("/instrumentation/gps/indicated-altitude-ft");
    insertOrder.emplace_back("/instrumentation/gps/indicated-ground-speed-kt");
    insertOrder.emplace_back("/instrumentation/gps/indicated-vertical-speed");
    insertOrder.emplace_back("/instrumentation/heading-indicator/indicated-heading-deg");
    insertOrder.emplace_back("instrumentation/magnetic-compass/indicated-heading-deg");
    insertOrder.emplace_back("/instrumentation/slip-skid-ball/indicated-slip-skid");
    insertOrder.emplace_back("/instrumentation/turn-indicator/indicated-turn-rate");
    insertOrder.emplace_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm");
    insertOrder.emplace_back("/controls/flight/aileron");
    insertOrder.emplace_back("/controls/flight/elevator");
    insertOrder.emplace_back("/controls/flight/rudder");
    insertOrder.emplace_back("/controls/flight/flaps");
    insertOrder.emplace_back("/controls/engines/current-/engine/throttle");
    insertOrder.emplace_back("/engines/engine/rpm");
}

 int DataReaderServer ::open(vector<string> vectString) {
     int sockfd, newsockfd, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int  n;

     /* First call to socket() function */
     sockfd = socket(AF_INET, SOCK_STREAM, 0);

     if (sockfd < 0) {
         perror("ERROR opening socket");
         return -1;
     }

     /* Initialize socket structure */
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = stoi(vectString.at(0));

     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

     /* Now bind the host address using bind() call.*/
     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
         perror("ERROR on binding");
         return -1;
     }

     listen(sockfd,5);
     clilen = sizeof(cli_addr);

     /* Accept actual connection from the client */
     newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
     this->newsockfd = newsockfd;
     if (newsockfd < 0) {
         perror("ERROR on accept");
         return -1;
     }

     thread receive(receiveValue, this->newsockfd, this->insertOrder, this->symbolTable, this->bindM);
     receive.detach();
}

void DataReaderServer :: receiveValue (int socketfd, vector<string> insertO, map<string, double>* symbolTable, map<string, string>* bindM) {
    vector<string> data;
    char buffer[1024];
    mutex mute;
    while (true) {
        bzero(&buffer, sizeof(buffer));
        read(socketfd, &buffer, sizeof(buffer));
        string s = buffer;
        stringstream ss(s);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            data.push_back(substr);
        }
        for (int i = 0; i < insertO.size(); i++) {
            if (bindM->count(insertO.at(i))) {
                lock_guard<mutex> lock(mute);
                symbolTable->find(bindM->find(insertO.at(i))->second)->second = stod((data.at(i)));
            }
        }
    }
}


vector<string> DataReaderServer :: split(string line, char character) {
    stringstream ss(line);
    vector<string> result;
    while( ss.good() )
    {
        string substr;
        getline( ss, substr,character);
        result.push_back(substr);
    }
    return result;
}