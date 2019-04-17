//
// Created by to on 12/18/18.
//

#include "ArgumentsHandlerCommand.h"

Expression *ArgumentsHandlerCommand::handleArgument(string argument) {
    return ex_factory(argument);
}

ArgumentsHandlerCommand::ArgumentsHandlerCommand(const ExpresionFactory &ex_factory) : ex_factory(ex_factory) {}
