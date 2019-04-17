//
// Created by to on 12/17/18.
//

#include "CommandExpression.h"


CommandExpression::CommandExpression(Command *command, const vector_iterator &it) : command(
        command), it(it){}


double CommandExpression::calculate() {
    return command->doCommand(it);
}

string CommandExpression::toString() {
    return "Command";
}

CommandExpression::~CommandExpression() {}
