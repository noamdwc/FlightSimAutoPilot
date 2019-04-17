//
// Created by to on 12/15/18.
//

#ifndef FLIGHTSIMULATO_SHUNTINGYARD_H
#define FLIGHTSIMULATO_SHUNTINGYARD_H


#include "Div.h"
#include "Mul.h"
#include "Minus.h"
#include "Plus.h"
#include "Number.h"
#include "Bigger.h"
#include "BiggerEqual.h"
#include "Smaller.h"
#include "SmallerEqual.h"
#include "Equal.h"
#include "NotEqual.h"
#include <queue>
#include <stack>
#include "../SymbolTable.h"


#include "../ErrorMessages.h"

class ExpresionFactory {
    deque<string> postfix;
    SymbolTable tables;


public:

    /**
     * get a string, use shuntingYard to turn it into postfix, and then turn that to an Expression
     * @param infix
     * @return
     */
    Expression *operator()(string infix);


    ExpresionFactory(SymbolTable &tables);

private:

    /**
     * get a string of expression in infix and turn it into postfix. the postfix is a member of the class.
     * this function is an implementation of the shunting-yard algorithm
     * @param expression - expression as string in infix
     */
    void shuntingYard(const string expression);

    /**
     * turn the infix that is a member of the class and use it to make an Expression pointer and empty the deque.
     * this function wont work if shuntingYard wasn't called first
     * @return a pointer of Expression the postfix represent
     */
    Expression *postfixToExpression();


    /**
     * call postfixToExpression 2 times in reverse to give each one of them a value in reverse order
     * @param ex1 - pointer to assing  the second time
     * @param ex2 - pointer to assing  the first time
     */
    void assignedInReverse(Expression *&ex1, Expression *&ex2);

    /**
     * check if the first operator in the stack is precedence then the giving operator
     * @param stack_operators - a tack of operator in string
     * @param operator2  - an operator in sring
     * @return true if the first element in the stack is precedence than the giving operator
     */
    bool isFirstPrecedenceBigger(const stack<string> stack_operators, const string operator2) const;

    /**
     * check if the given char is a sign of neg number
     * @param c  - the given char
     * @param i - the index in the expression that the cahr at
     * @param expression - the expression hum self
     * @return true if the c is a sign for a neg number
     */
    bool isNeg(char c, int i, string expression);

    /**
     * replace all ths symnbols of var with their value in a given string
     * @param expression - the given string
     */
    void replaceVar(string &expression);

    /**
     * find  all apearence
     * @param ori - the string to change
     * @param search - the string to replace
     * @param replace - the string to replace with
     */
    void replaceSubstring(string &ori, const string &search, const string &replace) const;

    /**
     * check if the giving operator is an oprator made form 2 chars
     * @param operator_str - the given operator
     * @param expression - the all expression
     * @param i - the index of the the given operator is
     * @return true if this a 2 char operator, false otherwise
     */
    bool isTwoCharOperator(string operator_str, string expression, int i);

    void dealWithOperator(string new_operator, string expression, stack<string> *operators, int &i, int &counter);


};


#endif //FLIGHTSIMULATO_SHUNTINGYARD_H
