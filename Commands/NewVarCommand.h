//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_NEWVARCOMMAND_H
#define FLIGHTSIMULATO_NEWVARCOMMAND_H

#include "TableHolderCommand.h"
#include "../ErrorMessages.h"
#include "VarAssignCommand.h"


class NewVarCommand : public TableHolderCommand {
    VarAssignCommand *assignCommand;
public:


    NewVarCommand(const ExpresionFactory &ex_factory, const SymbolTable &table, VarAssignCommand *assignCommand);

    int doCommand(vector_iterator it) override;
};


#endif //FLIGHTSIMULATO_NEWVARCOMMAND_H
