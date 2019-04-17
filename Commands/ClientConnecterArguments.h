//
// Created by to on 12/23/18.
//

#ifndef FLIGHTSIMULATO_CLIENTCONNECTERARGUMENTS_H
#define FLIGHTSIMULATO_CLIENTCONNECTERARGUMENTS_H


#include "../SymbolTable.h"

class ClientConnecterArguments {
//(string ip, int port, SymbolTable &st)
    string ip;
    int port;
    SymbolTable *table;
public:
    ClientConnecterArguments(const string &ip, int port, SymbolTable *table);

    const string &getIp() const;

    int getPort() const;

    SymbolTable *getTable() const;

};


#endif //FLIGHTSIMULATO_CLIENTCONNECTERARGUMENTS_H
