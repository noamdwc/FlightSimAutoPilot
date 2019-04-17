//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_TABLEHOLDERCOMMAND_H
#define FLIGHTSIMULATO_TABLEHOLDERCOMMAND_H

#include "ArgumentsHandlerCommand.h"
#include "../SymbolTable.h"

#define BIND_SYMBOL "bind"

class TableHolderCommand : public ArgumentsHandlerCommand{

    SymbolTable table;
public:

    TableHolderCommand(const ExpresionFactory &ex_factory, const SymbolTable &table);

    SymbolTable &getTable();

    /**
     * bind two symbols together
     * @param it
     * @return
     */
    int bind(vector_iterator it);


};


#endif //FLIGHTSIMULATO_TABLEHOLDERCOMMAND_H
