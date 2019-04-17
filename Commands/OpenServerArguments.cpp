//
// Created by to on 12/23/18.
//

#include "OpenServerArguments.h"

OpenServerArguments::OpenServerArguments(int port, double hrz, SymbolTable *ts) : port(port), hrz(hrz), ts(ts) {}

int OpenServerArguments::getPort() const {
    return port;
}

double OpenServerArguments::getHrz() const {
    return hrz;
}

SymbolTable *OpenServerArguments::getTable() const {
    return ts;
}
