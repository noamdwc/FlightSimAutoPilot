//
// Created by to on 12/29/18.
//

#ifndef FLIGHTSIMULATO_STREAMSETABLE_H
#define FLIGHTSIMULATO_STREAMSETABLE_H

#include <istream>

using namespace std;

class StreamSetable {
public:
    /**
     * set a new stream for the func_factory
     * @param new_stream
     */
    virtual void setStream(istream *new_stream) = 0;
};



#endif //FLIGHTSIMULATO_STREAMSETABLE_H
