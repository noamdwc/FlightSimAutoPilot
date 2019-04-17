//
// Created by to on 12/14/18.
//

#ifndef FLIGHTSIMULATO_MINUS_H
#define FLIGHTSIMULATO_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression{
public:
    Minus(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;

};


#endif //FLIGHTSIMULATO_MINUS_H
