//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_BIGGEREQUAL_H
#define FLIGHTSIMULATO_BIGGEREQUAL_H

#include "BinaryExpression.h"

class BiggerEqual : public BinaryExpression{
public:
    BiggerEqual(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;
};


#endif //FLIGHTSIMULATO_BIGGEREQUAL_H
