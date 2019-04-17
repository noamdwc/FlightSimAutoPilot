//
// Created by to on 12/17/18.
//

#include <iostream>
#include "Server.h"


string Server::getMsg(int newsockfd) {
    char buffer[BUFFER_SIZE];
    /* If connection is established then start communicating */
    bzero(buffer, BUFFER_SIZE);
    int n = read(newsockfd, buffer, BUFFER_SIZE - 1);

    if (n < 0) {
        throw SERVER_ERROR;
    }

    return string(buffer);
}


void *Server::open(void *arguments1) {
    OpenServerArguments *arguments = (OpenServerArguments *) arguments1;
    bool is_first_msg_in = false;
    int port = arguments->getPort();
    double hrz = arguments->getHrz();
    SymbolTable *table = arguments->getTable();
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        throw SERVER_ERROR;
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw SERVER_ERROR;
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    table->addSocket(sockfd);
    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        throw SERVER_ERROR;
    }

    table->lockMutex();
    table->addSocket(newsockfd);
    table->unlcokMutex();
    //start getting input:
    while (!table->isInExitMode()) {
        string msg;
        //get at least 1 set of data
        while (msg.find("\n") == string::npos) {
            msg += getMsg(newsockfd);
        }
        //get exactly one set of data
        string set_data = msg.substr(0, msg.find_first_of('\n'));

        //put the rest of the data to be a part of the next set
        msg = msg.substr(msg.find_first_of('\n') + 1, msg.size() - 1);

        while (msg[0] == '\n') {
            msg = msg.substr(1, msg.size() - 1);
        }

        //split and update
        vector<string> values = split(set_data, ",");
        vector<string> paths = PATHS;
        //update the table

        table->lockMutex();
        if (!set_data.empty()) {
            if (!is_first_msg_in) {
                table->severOpened();
                is_first_msg_in = !is_first_msg_in;
            }
            for (int i = 0; i < values.size(); ++i) {
                double value = strtod(values[i].c_str(), nullptr);
                table->updateFromServer(paths[i], value);
            }
        }
        table->unlcokMutex();
        usleep(1 / hrz);
    }
    table->severClosed();
    return NULL;
}
