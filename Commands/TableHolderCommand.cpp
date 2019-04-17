//
// Created by to on 12/17/18.
//

#include "TableHolderCommand.h"


SymbolTable &TableHolderCommand::getTable() {
    return table;
}

TableHolderCommand::TableHolderCommand(const ExpresionFactory &ex_factory, const SymbolTable &table)
        : ArgumentsHandlerCommand(ex_factory), table(table) {}

int TableHolderCommand::bind(vector_iterator it) {
    int counter = 0;
    string bind = *(it + counter);
    counter++;
    string bind_with = *(it + counter);
    counter++;

    getTable().bind(bind, bind_with);
    return counter;
}
