//
// Created by nikol on 12/20/18.
//

#include "PrintCommand.h"

#define EQUALSTO " = "

int PrintCommand::doCommand(vector_iterator it) {
    int counter = 0;
    string::iterator it_str = (*it).begin();
    counter++;
    string printable = "";
    //string
    if ((*it_str) == '\"') {
        it_str++;
        while ((*it_str) != '\"') {
            printable += *it_str;
            it_str++;

        }
        //print!
        cout << printable << endl;
    } else {
        Expression *ex = handleArgument(*it);
        cout << ex->calculate() << endl;
        delete (ex);
    }
    return counter;
}

PrintCommand::PrintCommand(const ExpresionFactory &ex_factory, const SymbolTable &table) : TableHolderCommand(
        ex_factory, table) {}



