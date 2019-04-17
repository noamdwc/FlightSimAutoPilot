//
// Created by to on 12/14/18.
//

#include "Div.h"

Div::Div(Expression *left_ex, Expression *right_ex) : BinaryExpression(left_ex, right_ex) {}

double Div::calculate() {
    return getLeft()->calculate() / getRight()->calculate();
}

string Div::toString() {
    return "(" + getLeft()->toString() + ") / " + "(" + getRight()->toString() + ")";
}
