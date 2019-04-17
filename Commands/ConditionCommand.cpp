//
// Created by to on 12/20/18.
//

#include "ConditionCommand.h"

ConditionCommand::ConditionCommand(const ExpresionFactory &ex_factory, const FuncCommandFactory &func_factory)
        : ArgumentsHandlerCommand(ex_factory), func_factory(func_factory) {}

FuncCommand *ConditionCommand::getFunc() {
    return func_factory.createFuncCommand();
}

void ConditionCommand::setStream(istream *new_stream) {
    func_factory.setStream(new_stream);
}
