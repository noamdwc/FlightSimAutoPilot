//
// Created by to on 12/15/18.
//


#include <thread>
#include "OpenDataServerCommand.h"

int OpenDataServerCommand::doCommand(vector_iterator it) {

    int counter = 0;
    Expression *ex = handleArgument(*it);
    double port = ex->calculate();
    counter++;
    delete (ex);
    ex = handleArgument((*(it + counter)));
    double hrz = ex->calculate();
    counter++;
    delete (ex);
    SymbolTable *tamp = &getTable();
    auto *arguments = new OpenServerArguments(port, hrz, tamp);
    pthread_t pthread;
    pthread_create(&pthread, nullptr, Server::open, (void *) arguments);


    return counter;
}

OpenDataServerCommand::OpenDataServerCommand(const ExpresionFactory &ex_factory, const SymbolTable &table)
        : TableHolderCommand(ex_factory, table) {}

