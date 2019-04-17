//
// Created by nikol on 12/20/18.
//

#ifndef FLIGHTSIMULATO_PRINTCOMMAND_H
#define FLIGHTSIMULATO_PRINTCOMMAND_H

#include "../ErrorMessages.h"
#include "TableHolderCommand.h"
#include <iostream>
using namespace std;

class PrintCommand: public TableHolderCommand{
public:
    PrintCommand(const ExpresionFactory &ex_factory, const SymbolTable &table);

public:



    /**
     * gets iterator to the first element after the word print
     * @param it_str
     * @return iterators new position
     */
    int doCommand(vector_iterator it_str) override;

};


#endif //FLIGHTSIMULATO_PRINTCOMMAND_H
