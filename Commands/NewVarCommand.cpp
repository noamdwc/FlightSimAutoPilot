//
// Created by to on 12/18/18.
//

#include "NewVarCommand.h"

int NewVarCommand::doCommand(vector_iterator it) {

    int counter = 0;
    string symbol = *it;
    counter++;
    //check this is a new var
    if (getTable().getEx(it) != NULL) {
        throw SYNTAX_ERROR;
    }
    return assignCommand->doCommand(it);

}

NewVarCommand::NewVarCommand(const ExpresionFactory &ex_factory, const SymbolTable &table,
                             VarAssignCommand *assignCommand) : TableHolderCommand(ex_factory, table),
                                                                assignCommand(assignCommand) {}
