//
// Created by to on 12/17/18.
//

#include "Bigger.h"

double Bigger::calculate() {
    return getLeft()->calculate() > getRight()->calculate();
}

string Bigger::toString() {
    return "(" + getLeft()->toString() + ") > " + "(" + getRight()->toString() + ")";
}

Bigger::Bigger(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}
