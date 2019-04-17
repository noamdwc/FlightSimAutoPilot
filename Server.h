//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_SERVER_H
#define FLIGHTSIMULATO_SERVER_H


#include <stdio.h>
#include <stdlib.h>


#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>

#include <sys/socket.h>

#include "SymbolTable.h"
#include "ErrorMessages.h"
#include "Spliter.h"
#include "Commands/OpenServerArguments.h"

#define PATHS {"\"/instrumentation/airspeed-indicator/indicated-speed-kt\"","\"/instrumentation/altimeter/indicated-altitude-ft\"","\"/instrumentation/altimeter/pressure-alt-ft\"","\"/instrumentation/attitude-indicator/indicated-pitch-deg\"","\"/instrumentation/attitude-indicator/indicated-roll-deg\"","\"/instrumentation/attitude-indicator/internal-pitch-deg\"","\"/instrumentation/attitude-indicator/internal-roll-deg\"","\"/instrumentation/encoder/indicated-altitude-ft\"","\"/instrumentation/encoder/pressure-alt-ft\"","\"/instrumentation/gps/indicated-altitude-ft\"","\"/instrumentation/gps/indicated-ground-speed-kt\"","\"/instrumentation/gps/indicated-vertical-speed\"","\"/instrumentation/heading-indicator/indicated-heading-deg\"","\"/instrumentation/magnetic-compass/indicated-heading-deg\"","\"/instrumentation/slip-skid-ball/indicated-slip-skid\"","\"/instrumentation/turn-indicator/indicated-turn-rate\"","\"/instrumentation/vertical-speed-indicator/indicated-speed-fpm\"","\"/controls/flight/aileron\"","\"/controls/flight/elevator\"","\"/controls/flight/rudder\"","\"/controls/flight/flaps\"","\"/controls/engines/engine/throttle\"","\"/engines/engine/rpm\""}
#define BUFFER_SIZE 1024

using namespace std;


class Server : public Spliter {


public:
    static void *open(void *arguments);

    static string getMsg(int newsockfd);


};


#endif //FLIGHTSIMULATO_SERVER_H
