//
// Created by to on 12/22/18.
//

#ifndef FLIGHTSIMULATO_SPLITER_H
#define FLIGHTSIMULATO_SPLITER_H

#include <string>
#include <vector>

using namespace std;

class Spliter {
public:
    /**
     * split a stirng by a given superator, ignore " "
     * @param seporator - the given superator
     * @return the string in prats in vector
     */
    static vector<string> split(string line, string seporator);


};


#endif //FLIGHTSIMULATO_SPLITER_H
