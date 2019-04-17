//
// Created by to on 12/18/18.
//

#include "IfCommand.h"


int IfCommand::doCommand(vector_iterator it) {
    int counter = 0;
    vector_iterator dummy;
    FuncCommand *func = getFunc();
    Expression *ex = handleArgument(*it);
    if (ex->calculate()) {
        func->doCommand(dummy);
    }
    delete (ex);
    if (!func->isOpenAtLine()) {
        counter++;
    }
    counter++;
    return counter;
}

IfCommand::IfCommand(const ExpresionFactory &ex_factory, const FuncCommandFactory &func_factory) : ConditionCommand(
        ex_factory, func_factory) {}

