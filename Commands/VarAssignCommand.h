//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_VARASSIGNCOMMAND_H
#define FLIGHTSIMULATO_VARASSIGNCOMMAND_H

#include "TableHolderCommand.h"

class VarAssignCommand : public TableHolderCommand{
public:
    VarAssignCommand(const ExpresionFactory &ex_factory, const SymbolTable &table);

    int doCommand(vector_iterator it) override;
};


#endif //FLIGHTSIMULATO_VARASSIGNCOMMAND_H
