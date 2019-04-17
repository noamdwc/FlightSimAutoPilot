//
// Created by to on 12/14/18.
//

#include "Minus.h"

Minus::Minus(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}

double Minus::calculate() {
    return getLeft()->calculate() - getRight()->calculate();
}

string Minus::toString() {
    return "(" + getLeft()->toString() + ") - " + "(" + getRight()->toString() + ")";
}
