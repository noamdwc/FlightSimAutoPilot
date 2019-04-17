//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_COMMANDEXPRESSION_H
#define FLIGHTSIMULATO_COMMANDEXPRESSION_H

#include "../Commands/Command.h"
#include "Expression.h"


class CommandExpression : public Expression {
    Command *command;
    vector_iterator it;

public:
    /**
     * create a CommandExpression with a Command pointer and an iterator for a vector of string
     * @param command - a pointer to the Command
     * @param it - the iterator of a vector of a string
     */
    CommandExpression(Command *command, const vector_iterator &it);

    /**
     * activate the doCommand method of the Command
     * @return - how much of the elements of the vector<string> were used by the Command
     */
    double calculate() override;

    /**
     * this function is used for tests only, so in this case it will only return "Command"
     * @return - "Command"
     */
    string toString() override;

    ~CommandExpression() override;


};


#endif //FLIGHTSIMULATO_COMMANDEXPRESSION_H
