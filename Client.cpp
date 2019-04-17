//
// Created by to on 12/18/18.
//

#include <iostream>
#include "Client.h"

Client::Client(string &ip, int port) {

    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        throw CLIENT_ERROR;
    }

    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        throw CLIENT_ERROR;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Now connect to the server */
    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw CLIENT_ERROR;
    }


}

int Client::getSockfd() const {
    return sockfd;
}

void Client::sendMsg(string msg) {

    /* Send message to the server */
    int n = write(sockfd, msg.c_str(), msg.length());

    if (n < 0) {
        throw CLIENT_ERROR;
    }

}
