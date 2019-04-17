//
// Created by to on 12/21/18.
//

#ifndef FLIGHTSIMULATO_INITIALIZER_H
#define FLIGHTSIMULATO_INITIALIZER_H

#include "Lexer.h"
#include "Expression/ExpresionFactory.h"
#include "Initializer.h"

#include <fstream>
#include "Commands/NewVarCommand.h"
#include "Commands/VarAssignCommand.h"
#include "Commands/PrintCommand.h"
#include "Commands/FuncCommandFactory.h"
#include "Commands/IfCommand.h"
#include "Commands/WhileCommand.h"
#include "Commands/OpenDataServerCommand.h"
#include "Commands/ConnactCommand.h"
#include "Commands/EnterCommand.h"
#include "Commands/SleepCommand.h"
#include "StreamSetable.h"


class InterpreterInitializer : public Initializer {
    SymbolTable st;
    ExpresionFactory ex_factory;
    vector<StreamSetable *> stream_setables;
    Lexer *lexer;
    ifstream *stream;
    bool is_from_file;
    FuncCommandFactory *factory_to_del;

public:
    /**
     * get the lexer the interpreter using
     * @return the lexer the interpreter using
     */
    Lexer *getLexer() override;

    /**
     * inti an interpreter that interpreter text from a file from a given path
     * @param path - the given path
     */
    InterpreterInitializer(string path);

    /**
     * get the SymbolTable the interpreter using
     * @return the SymbolTable the interpreter using
     */
    SymbolTable &getTable() override;

    /**
     * start the interpreter
     */
    void start() override;

    /**
     * reset all the setable to have a new stream
     * @param stream - the stream to reset with all the setable
     */
    void initializeNewStream(istream *stream) override;

    /**
     * a destructor, free all the allocated memory
     */
    virtual ~InterpreterInitializer();

    /**
     * check if exit mode have started (meaning closing the program)
     * @return true if in exit mode, false otherwise
     */
    bool isInExitMode() override;

private:
    void initialize() override;
};


#endif //FLIGHTSIMULATO_INITIALIZER_H
