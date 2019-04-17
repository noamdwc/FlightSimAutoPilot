//
// Created by to on 12/18/18.
//

#include "NotEqual.h"

double NotEqual::calculate() {
    return getLeft()->calculate() != getRight()->calculate();
}

string NotEqual::toString() {
    return "(" + getLeft()->toString() + ") != " + "(" + getRight()->toString() + ")";
}

NotEqual::NotEqual(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}
