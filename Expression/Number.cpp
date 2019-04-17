//
// Created by to on 12/14/18.
//

#include <algorithm>
#include "Number.h"


double Number::calculate() {
    return var_;
}

string Number::toString() {
    return to_string(var_);
}

Number::Number(string &var_str) {
    try {
        this->var_ = strtod(var_str.c_str(), nullptr);
    } catch (exception &e) {
        throw SYNTAX_ERROR;
    }
}

Number::Number(double var_) : var_(var_) {}


Number::~Number() {}
