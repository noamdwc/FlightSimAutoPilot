//
// Created by nikol on 12/23/18.
//

#include "EnterCommand.h"

int EnterCommand::doCommand(vector_iterator it) {
    char ch='0';
    stream->get(&ch, 1);
    return 0;
}

EnterCommand::EnterCommand(istream *stream) : stream(stream) {}

void EnterCommand::setStream(istream *new_stream) {
    stream = new_stream;

}
