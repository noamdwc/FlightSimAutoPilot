//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_WHILECOMMAND_H
#define FLIGHTSIMULATO_WHILECOMMAND_H

#include "ConditionCommand.h"


class WhileCommand : public ConditionCommand {
public:
    WhileCommand(const ExpresionFactory &ex_factory, const FuncCommandFactory &func_factory);

    int doCommand(vector_iterator it) override;
};


#endif //FLIGHTSIMULATO_WHILECOMMAND_H
