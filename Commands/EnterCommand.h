//
// Created by nikol on 12/23/18.
//

#ifndef FLIGHTSIMULATO_ENTERCOMMAND_H
#define FLIGHTSIMULATO_ENTERCOMMAND_H

#include "Command.h"
#include <istream>
#include "../StreamSetable.h"

class EnterCommand: public Command, public StreamSetable{
    istream *stream;
public:
    int doCommand(vector_iterator it) override;

    EnterCommand(istream *stream);

    void setStream(istream *new_stream) override;
};


#endif //FLIGHTSIMULATO_ENTERCOMMAND_H
