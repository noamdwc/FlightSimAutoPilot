//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_NOTEQUAL_H
#define FLIGHTSIMULATO_NOTEQUAL_H

#include "BinaryExpression.h"

class NotEqual : public BinaryExpression {
public:
    NotEqual(Expression *left_ex, Expression *right_ex);

    double calculate() override;

    string toString() override;

};


#endif //FLIGHTSIMULATO_NOTEQUAL_H
