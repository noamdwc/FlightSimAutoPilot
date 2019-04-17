//
// Created by to on 12/17/18.
//

#include "Equal.h"

double Equal::calculate() {
    return getLeft()->calculate() == getRight()->calculate();
}

string Equal::toString() {
    return "(" + getLeft()->toString() + ") == " + "(" + getRight()->toString() + ")";
}

Equal::Equal(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}
