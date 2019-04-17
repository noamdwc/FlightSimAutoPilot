//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_FUNCCOMMANDFACTORY_H
#define FLIGHTSIMULATO_FUNCCOMMANDFACTORY_H


#include "../Lexer.h"
#include "FuncCommand.h"
#include "../StreamSetable.h"

class FuncCommandFactory : public StreamSetable{
    Initializer *initializer;
    istream *stream;
public:
    FuncCommandFactory(Initializer *initializer, istream *stream);

    /**
     * create a FuncCommand
     * @return
     */
    FuncCommand *createFuncCommand() const;

    void setStream(istream *new_stream) override;

};


#endif //FLIGHTSIMULATO_FUNCCOMMANDFACTORY_H
