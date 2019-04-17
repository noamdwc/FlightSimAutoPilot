//
// Created by nikol on 12/20/18.
//

#ifndef FLIGHTSIMULATO_SLEEPCOMMAND_H
#define FLIGHTSIMULATO_SLEEPCOMMAND_H

#include <unistd.h>
#include "ArgumentsHandlerCommand.h"

class SleepCommand: public ArgumentsHandlerCommand{

public:
    SleepCommand(const ExpresionFactory &ex_factory);

    int doCommand(vector_iterator it) override;

};


#endif //FLIGHTSIMULATO_SLEEPCOMMAND_H
