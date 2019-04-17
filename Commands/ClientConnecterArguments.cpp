//
// Created by to on 12/23/18.
//

#include "ClientConnecterArguments.h"

ClientConnecterArguments::ClientConnecterArguments(const string &ip, int port, SymbolTable *table) : ip(ip), port(port),
                                                                                                     table(table) {}

const string &ClientConnecterArguments::getIp() const {
    return ip;
}

int ClientConnecterArguments::getPort() const {
    return port;
}

SymbolTable *ClientConnecterArguments::getTable() const {
    return table;
}
