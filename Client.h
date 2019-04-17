//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_CLIENT_H
#define FLIGHTSIMULATO_CLIENT_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>


#include "Spliter.h"
#include "ErrorMessages.h"


#include <iostream>

#define BUFFER_SIZE 1024

using namespace std;

class Client : public Spliter {
    int sockfd;


public:
    /**
     * connect to the server with the given ip and port
     * @param ip - the given ip
     * @param port - the given port
     */
    Client(string& ip, int port);

    /**
     * send a given string to the server
     * @param msg - the given string
     */
    void sendMsg(string msg);

    /**
     * get the socket the client using
     * @return the socket the client using
     */
    int getSockfd() const;


};


#endif //FLIGHTSIMULATO_CLIENT_H
