//
// Created by to on 12/14/18.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left_ex, Expression *right_ex) : left_ex(left_ex), right_ex(right_ex) {}


Expression *BinaryExpression::getLeft() const {
    return left_ex;
}

Expression *BinaryExpression::getRight() const {
    return right_ex;
}

BinaryExpression::~BinaryExpression() {
    delete (left_ex);
    delete (right_ex);

}
