//
// Created by to on 12/14/18.
//

#ifndef FLIGHTSIMULATO_NUMBER_H
#define FLIGHTSIMULATO_NUMBER_H

#include <stdexcept>
#include "Expression.h"
#include "../ErrorMessages.h"


class Number : public Expression {
    double var_;
public:
    Number(string &var_str);

    Number(double var_);

    double calculate() override;

    string toString() override;

    ~Number() override;

};



#endif //FLIGHTSIMULATO_NUMBER_H
