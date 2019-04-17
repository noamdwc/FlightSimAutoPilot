//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_BIGGER_H
#define FLIGHTSIMULATO_BIGGER_H

#include "BinaryExpression.h"

class Bigger : public BinaryExpression {
public:
    Bigger(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;
};


#endif //FLIGHTSIMULATO_BIGGER_H
