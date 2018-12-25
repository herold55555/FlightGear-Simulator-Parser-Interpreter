//
// Created by herold55 on 12/17/18.
//

#include <cstring>
#include <iostream>
#include "DataClient.h"
int DataClient ::connect(vector<string> vect) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    portno = stoi(vect.at(1));

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }
    this->socketConnect = sockfd;
    server = gethostbyname(vect.at(0).c_str());

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (::connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }
}

void DataClient:: set (string str) {
    int n;
    string temp = "set";
    temp += " ";
    temp += str;
    temp += "\r\n";
    const char* buffer = temp.c_str();
    if (::send(this->socketConnect, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR writting to socket");
        exit(1);
    }
}
