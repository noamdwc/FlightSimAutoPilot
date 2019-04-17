//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_SMALLEREQUAL_H
#define FLIGHTSIMULATO_SMALLEREQUAL_H

#include "BinaryExpression.h"

class SmallerEqual : public BinaryExpression{
public:
    SmallerEqual(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;

};


#endif //FLIGHTSIMULATO_SMALLEREQUAL_H
