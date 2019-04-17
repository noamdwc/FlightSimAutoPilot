//
// Created by to on 12/17/18.
//

#include "VarAssignCommand.h"

int VarAssignCommand::doCommand(vector_iterator it) {
    int counter = 0;
    string symbol = *it;
    counter++;
    //check that there is a =
    try {
        string check = *(it + counter);
        counter++;
        if (check != "=") {
            throw SYNTAX_ERROR;
        }
    } catch (logic_error &e) {
        string zero_dummy = "0";
        Expression *number = new Number(zero_dummy);
        getTable().setEx(symbol, number);
        return counter;
    }

    string value = *(it + counter);
    counter++;
    //check if bind
    if (value == BIND_SYMBOL) {
        string bind_with = *(it + counter);
        counter++;
        getTable().bind(symbol, bind_with);
        return counter;
    }
    Expression* ex = handleArgument(value);
    getTable().setEx(symbol, ex);
    return counter;
}

VarAssignCommand::VarAssignCommand(const ExpresionFactory &ex_factory, const SymbolTable &table) : TableHolderCommand(
        ex_factory, table) {}


