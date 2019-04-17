//
// Created by to on 12/14/18.
//

#ifndef FLIGHTSIMULATO_DIV_H
#define FLIGHTSIMULATO_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    Div(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;
};


#endif //FLIGHTSIMULATO_DIV_H
