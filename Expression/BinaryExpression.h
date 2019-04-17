//
// Created by to on 12/14/18.
//

#ifndef FLIGHTSIMULATO_BINARYEXPRESSION_H
#define FLIGHTSIMULATO_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
    Expression *left_ex;
    Expression *right_ex;

public:
    /**
     * create a BinaryExpression using two pointer for the two Expression
     * @param left_ex - the left Expression
     * @param right_ex - the right Expression
     */
    BinaryExpression(Expression *left_ex, Expression *right_ex);

    /**
     * get the left expression of the binary expression
     * @return the left Expression
     */
    Expression *getLeft() const;


    /**
     * get the right expression of the binary expression
     * @return the right Expression
     */
    Expression *getRight() const;

    /**
     * delete both the Expression
     */
    ~BinaryExpression() override;

};


#endif //FLIGHTSIMULATO_BINARYEXPRESSION_H
