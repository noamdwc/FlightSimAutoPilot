//
// Created by nikol on 12/12/18.
//

#ifndef FLIGHTSIMULATO_COMMAND_H
#define FLIGHTSIMULATO_COMMAND_H


#include <string>
#include <vector>


using namespace std;

//define the type vector<string>::iterator as vector_iterator
typedef vector<string>::iterator vector_iterator;

class Command {

public:
    /**
     * active the command
     * @param it - an iterator to the start of the arguments in a vector of the line
     * @param end  - the iterator to the end of the vector
     * @return how much elements were use from the vector
     */
    virtual int doCommand(vector_iterator it) = 0;

    virtual ~Command() {};


};


#endif //FLIGHTSIMULATO_COMMAND_H
