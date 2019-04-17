//
// Created by to on 12/22/18.
//


#include "ConnactCommand.h"

ConnactCommand::ConnactCommand(const ExpresionFactory &ex_factory, const SymbolTable &table) : TableHolderCommand(
        ex_factory, table) {}

int ConnactCommand::doCommand(vector_iterator it) {
    int counter = 0;
    string ip = *it;
    counter++;
    Expression *ex = handleArgument(*(it + counter));
    int port = ex->calculate();
    delete (ex);
    counter++;
    SymbolTable *st = &getTable();
    ClientConnecterArguments *arguments = new ClientConnecterArguments(ip, port, st);
    ClientConnecter::connect(arguments);


    return counter;
}
