//
// Created by to on 12/17/18.
//

#include "Smaller.h"

double Smaller::calculate() {
    return getLeft()->calculate() < getRight()->calculate();
}

string Smaller::toString() {
    return "(" + getLeft()->toString() + ") < " + "(" + getRight()->toString() + ")";
}

Smaller::Smaller(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}
