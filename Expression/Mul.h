//
// Created by to on 12/14/18.
//

#ifndef FLIGHTSIMULATO_MUL_H
#define FLIGHTSIMULATO_MUL_H

#include "BinaryExpression.h"

class Mul : public BinaryExpression{
public:
    Mul(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;

};


#endif //FLIGHTSIMULATO_MUL_H
