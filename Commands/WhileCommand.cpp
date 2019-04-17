//
// Created by to on 12/18/18.
//

#include "WhileCommand.h"


int WhileCommand::doCommand(vector_iterator it) {
    int counter = 0;
    vector_iterator dummy;
    FuncCommand *func = getFunc();
    Expression *ex = handleArgument(*it);
    while (ex->calculate()) {
        func->doCommand(dummy);
        delete (ex);
        ex = handleArgument(*it);
        if (func->isInExitMode()) {
            break;
        }
    }
    delete (ex);
    if (!func->isOpenAtLine()) {
        counter++;
    }
    counter++;
    return counter;
}

WhileCommand::WhileCommand(const ExpresionFactory &ex_factory, const FuncCommandFactory &func_factory)
        : ConditionCommand(ex_factory, func_factory) {}
