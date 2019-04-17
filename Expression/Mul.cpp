//
// Created by to on 12/14/18.
//

#include "Mul.h"

Mul::Mul(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}

double Mul::calculate() {
    return getLeft()->calculate() * getRight()->calculate();
}

string Mul::toString() {
    return "(" + getLeft()->toString() + ") * " + "(" + getRight()->toString() + ")";
}
