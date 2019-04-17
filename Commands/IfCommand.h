//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_IFCOMMAND_H
#define FLIGHTSIMULATO_IFCOMMAND_H

#include "ConditionCommand.h"


class IfCommand : public ConditionCommand{
public:
    IfCommand(const ExpresionFactory &ex_factory, const FuncCommandFactory &func_factory);

    int doCommand(vector_iterator it) override;


};


#endif //FLIGHTSIMULATO_IFCOMMAND_H
