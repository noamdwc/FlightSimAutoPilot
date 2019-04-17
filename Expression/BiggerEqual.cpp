//
// Created by to on 12/17/18.
//

#include "BiggerEqual.h"

double BiggerEqual::calculate() {
    return getLeft()->calculate() >= getRight()->calculate();
}

BiggerEqual::BiggerEqual(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}

string BiggerEqual::toString() {
    return "(" + getLeft()->toString() + ") >= " + "(" + getRight()->toString() + ")";
}
