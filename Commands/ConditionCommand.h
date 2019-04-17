//
// Created by to on 12/20/18.
//

#ifndef FLIGHTSIMULATO_CONDITIONCOMMAND_H
#define FLIGHTSIMULATO_CONDITIONCOMMAND_H


#include "ArgumentsHandlerCommand.h"
#include "FuncCommandFactory.h"
#include "../StreamSetable.h"

class ConditionCommand : public ArgumentsHandlerCommand, public StreamSetable {
    FuncCommandFactory func_factory;
public:
    ConditionCommand(const ExpresionFactory &ex_factory, const FuncCommandFactory &func_factory);

    /**
     * get the func to call when the condition is true
     * @return - the func to call
     */
    FuncCommand* getFunc();

    void setStream(istream *new_stream) override;


};


#endif //FLIGHTSIMULATO_CONDITIONCOMMAND_H
