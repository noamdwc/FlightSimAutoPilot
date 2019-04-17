//
// Created by to on 12/22/18.
//

#ifndef FLIGHTSIMULATO_CONNACTCOMMAND_H
#define FLIGHTSIMULATO_CONNACTCOMMAND_H

#include "TableHolderCommand.h"
#include <thread>
#include "ClientConnecter.h"

class ConnactCommand : public TableHolderCommand {
public:
    ConnactCommand(const ExpresionFactory &ex_factory, const SymbolTable &table);

    int doCommand(vector_iterator it) override;
};


#endif //FLIGHTSIMULATO_CONNACTCOMMAND_H
