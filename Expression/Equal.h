//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_EQUAL_H
#define FLIGHTSIMULATO_EQUAL_H

#include "BinaryExpression.h"

class Equal : public BinaryExpression{
public:
    Equal(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;

};


#endif //FLIGHTSIMULATO_EQUAL_H
