//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_ARGUMENTSHANDLERCOMMAND_H
#define FLIGHTSIMULATO_ARGUMENTSHANDLERCOMMAND_H

#include "Command.h"
#include "../Expression/ExpresionFactory.h"

class ArgumentsHandlerCommand : public Command {
    ExpresionFactory ex_factory;
public:
    ArgumentsHandlerCommand(const ExpresionFactory &ex_factory);

public:
    /**
     * turn the string argument to Expression
     * @param argument - the argument that need to be handled
     * @return the Expression the
     */
    Expression* handleArgument(string argument);

};


#endif //FLIGHTSIMULATO_ARGUMENTSHANDLERCOMMAND_H
