//
// Created by to on 12/23/18.
//

#ifndef FLIGHTSIMULATO_OPENSERVERARGUMENTS_H
#define FLIGHTSIMULATO_OPENSERVERARGUMENTS_H


#include "../SymbolTable.h"

class OpenServerArguments {
    int port;
    double hrz;
    SymbolTable * ts;
public:
    OpenServerArguments(int port, double hrz, SymbolTable *ts);

    int getPort() const;

    double getHrz() const;

    SymbolTable *getTable() const;

};


#endif //FLIGHTSIMULATO_OPENSERVERARGUMENTS_H
