//
// Created by to on 12/14/18.
//

#ifndef FLIGHTSIMULATO_EXPRESSION_H
#define FLIGHTSIMULATO_EXPRESSION_H

#include <string>

using namespace std;

class Expression {
public:
    /**
     * doing the mathematical calculation of the expression
     * @return the result of the mathematical calculation of the expression
     */
    virtual double calculate() = 0;

    /**
     * convert the giving expression to string.
     * this function will be used for testing
     * @return the expression as string
     */
    virtual string toString() = 0;

    virtual ~Expression() {};

};


#endif //FLIGHTSIMULATO_EXPRESSION_H
