//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_SMALLER_H
#define FLIGHTSIMULATO_SMALLER_H

#include "BinaryExpression.h"

class Smaller : public BinaryExpression {
public:
    Smaller(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;

};


#endif //FLIGHTSIMULATO_SMALLER_H
