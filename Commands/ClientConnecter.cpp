//
// Created by to on 12/22/18.
//

#include "ClientConnecter.h"
#include "iostream"

void *ClientConnecter::connect(void *arguments1) {
    ClientConnecterArguments *arguments = (ClientConnecterArguments *) arguments1;
    string ip = arguments->getIp();
    int port = arguments->getPort();
    SymbolTable *table = arguments->getTable();
    delete (arguments);

    while (true) {
        if (table->isServerOpen()) {
            break;
        }
    }

    Client *client = new Client(ip, port);
    table->addClient(client);
    return NULL;
}
