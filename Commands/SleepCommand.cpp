//
// Created by nikol on 12/20/18.
//

#include <chrono>
#include <thread>
#include "SleepCommand.h"

SleepCommand::SleepCommand(const ExpresionFactory &ex_factory) : ArgumentsHandlerCommand(ex_factory) {}

int SleepCommand::doCommand(vector_iterator it) {
    unsigned milliseconds_input=(unsigned int)stoul((*it));
    this_thread::sleep_for(chrono::milliseconds(milliseconds_input));
    //should be only one element in vector (it is the iterator)
    return 1;
}
