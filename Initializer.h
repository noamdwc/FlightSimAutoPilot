//
// Created by to on 12/24/18.
//

#ifndef FLIGHTSIMULATO_INTERPRETER_H
#define FLIGHTSIMULATO_INTERPRETER_H

#include "Lexer.h"
#include <istream>

class Initializer {
public:

    /**
     * initialize all the that is needed and return a lexer
     * @return
     */
    virtual void initialize() = 0;

    virtual SymbolTable &getTable() = 0;

    /**
     * change the stream from him we get the inputs
     * @param stream
     */
    virtual void initializeNewStream(istream *stream) = 0;

    /**
     * start the program
     */
    virtual void start() = 0;

    /**
     * get the lexer from with we use
     * @return the lexer we use
     */
    virtual Lexer *getLexer() = 0;

    /**
     *check if the program is in exit mode
     * @return true if the program is in exit true, false otherwise
     */
    virtual bool isInExitMode() = 0;

};


#endif //FLIGHTSIMULATO_INTERPRETER_H
