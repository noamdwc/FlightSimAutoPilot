//
// Created by to on 12/15/18.
//

#ifndef FLIGHTSIMULATO_OPENDATASERVERCOMMAND_H
#define FLIGHTSIMULATO_OPENDATASERVERCOMMAND_H

#include "TableHolderCommand.h"
#include "../Server.h"

class OpenDataServerCommand  : public TableHolderCommand{


public:
    int doCommand(vector_iterator it) override;

    OpenDataServerCommand(const ExpresionFactory &ex_factory, const SymbolTable &table);
};


#endif //FLIGHTSIMULATO_OPENDATASERVERCOMMAND_H
