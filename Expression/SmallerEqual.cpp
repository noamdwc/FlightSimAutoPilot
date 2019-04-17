//
// Created by to on 12/17/18.
//

#include "SmallerEqual.h"

double SmallerEqual::calculate() {
    return getLeft()->calculate() <= getRight()->calculate();
}

SmallerEqual::SmallerEqual(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}

string SmallerEqual::toString() {
    return "(" + getLeft()->toString() + ") <= " + "(" + getRight()->toString() + ")";
}
