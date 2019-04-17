//
// Created by to on 12/22/18.
//

#ifndef FLIGHTSIMULATO_CLIENTSENDER_H
#define FLIGHTSIMULATO_CLIENTSENDER_H

#include "../SymbolTable.h"
#include "ClientConnecterArguments.h"

class ClientConnecter {
public:
    /**
     * connect to a server using the given arguments
     * assuming the argument are from the ClientConnecterArguments type
     * @param arguments -  a pointer ClientConnecterArguments  cast as void* (for thread use)
     * @return NULL
     */
    static void* connect(void* arguments);


};


#endif //FLIGHTSIMULATO_CLIENTSENDER_H
