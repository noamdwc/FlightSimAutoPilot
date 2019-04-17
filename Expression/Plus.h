//
// Created by to on 12/14/18.
//

#ifndef FLIGHTSIMULATO_PLUS_H
#define FLIGHTSIMULATO_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression *left_ex, Expression *right_ex);

private:
    double calculate() override;

    string toString() override;
};


#endif //FLIGHTSIMULATO_PLUS_H
