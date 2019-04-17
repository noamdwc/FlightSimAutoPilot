//
// Created by to on 12/14/18.
//

#include "Plus.h"

Plus::Plus(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}

double Plus::calculate() {
    return getLeft()->calculate() + getRight()->calculate();
}

string Plus::toString() {
    return "(" + getLeft()->toString() + ") + " + "(" + getRight()->toString() + ")";
}
