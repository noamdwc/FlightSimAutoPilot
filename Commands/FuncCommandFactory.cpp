//
// Created by to on 12/18/18.
//

#include "FuncCommandFactory.h"


FuncCommand *FuncCommandFactory::createFuncCommand() const {
    FuncCommand *func = new FuncCommand(initializer, stream);
    initializer->getTable().addCommandToDel(func);
    return func;
}

FuncCommandFactory::FuncCommandFactory(Initializer *initializer, istream *stream) : initializer(initializer),
                                                                                    stream(stream) {}

void FuncCommandFactory::setStream(istream *new_stream) {
    FuncCommandFactory::stream = new_stream;
}

