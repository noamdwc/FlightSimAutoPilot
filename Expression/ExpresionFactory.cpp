//
// Created by to on 12/15/18.
//




#include "ExpresionFactory.h"


void ExpresionFactory::shuntingYard(const string expression) {
    stack<string> operators;
    string number;
    //count how manny arguments were pushed to the deque
    int counter = 0;
    for (int i = 0; i < expression.size(); ++i) {
        string new_operator;
        char c = expression[i];
        //if the char is a digit
        if ('0' <= c && c <= '9') {
            number += c;
        } else if (c == '.') {
            if (number.empty()) {
                throw SYNTAX_ERROR;
            }
            number += c;
        } else {
            //add the number to the postfix
            if (!number.empty()) {
                postfix.push_back(number);
                number = "";
            }
            switch (c) {
                //if c is " " continue
                case ' ':
                    continue;

                    //if c is "(" push it to the operators stack
                case '(':
                    if (!postfix.empty()) {
                        if (postfix.back() == "-") {
                            postfix.pop_back();
                            postfix.push_back("-1");
                            dealWithOperator("*", expression, &operators, i, counter);
                        }
                    }
                    new_operator.push_back(c);
                    operators.push(new_operator);
                    break;

                    //if c is ")" move all the operators in the stack that came after the "("  to postfix
                case ')':
                    while (operators.top() != "(") {
                        postfix.push_back(operators.top());
                        counter++;
                        operators.pop();
                    }
                    operators.pop();
                    break;
                    //if c is a normal operator
                default:
                    //check if this is the start of a neg number
                    if (isNeg(c, i, expression)) {
                        number.push_back(c);
                        continue;
                    }
                    new_operator.push_back(c);
                    dealWithOperator(new_operator, expression, &operators, i, counter);

                    break;
            }

        }
    }
    //push the last number to the postfix
    if (!number.empty()) {
        postfix.push_back(number);
        number = "";
    }
    //move all the operator in the stack to the postfix
    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

}

/*Explaining how the following function works:
 * I will use 3 lvl of precedence:
 * lower lvl - bool operator
 * mid lvl - +,-
 * top lvl - *,/
 *
 * the "(" is a spaicel operaotr and will be at even more importend then the top lvl
 *
 * I will check if an operaor belong to lvl and by that cut the options until i can know for sure
 * */
bool ExpresionFactory::isFirstPrecedenceBigger(const stack<string> stack_operators, const string operator2) const {
    //check if the stack is empty
    if (stack_operators.empty()) {
        return false;
    }
    string operator1 = stack_operators.top();
    if (operator1 == "(") {
        return false;
    }

    if (operator2 == "(") {
        return true;
    }

    //is operator1 is in lower lvl
    if (operator1 == "<" || operator1 == ">" || operator1 == "==" || operator1 == "!=" || operator1 == "<=" ||
        operator1 == ">=") {
        return false;
    }
    //is operator2 is in top lvl
    if (operator2 == "*" || operator2 == "/") {
        return false;
    }
    //is operator is in lower lvl
    if (operator2 == "<" || operator2 == ">" || operator2 == "==" || operator2 == "!=" || operator2 == "<=" ||
        operator2 == ">=") {
        return true;
    }
    //is operator1 is in top lvl
    return operator1 == "*" || operator1 == "/";

}


Expression *ExpresionFactory::postfixToExpression() {

    string element = postfix.back();
    postfix.pop_back();
    Expression *ex1;
    Expression *ex2;

    if (element == "+") {
        assignedInReverse(ex1, ex2);
        return new Plus(ex1, ex2);
    } else if (element == "-") {
        assignedInReverse(ex1, ex2);
        return new Minus(ex1, ex2);
    } else if (element == "*") {
        assignedInReverse(ex1, ex2);
        return new Mul(ex1, ex2);
    } else if (element == "/") {
        assignedInReverse(ex1, ex2);
        return new Div(ex1, ex2);
    } else if (element == "<") {
        assignedInReverse(ex1, ex2);
        return new Smaller(ex1, ex2);
    } else if (element == "<=") {
        assignedInReverse(ex1, ex2);
        return new SmallerEqual(ex1, ex2);
    } else if (element == ">") {
        assignedInReverse(ex1, ex2);
        return new Bigger(ex1, ex2);
    } else if (element == ">=") {
        assignedInReverse(ex1, ex2);
        return new BiggerEqual(ex1, ex2);
    } else if (element == "==") {
        assignedInReverse(ex1, ex2);
        return new Equal(ex1, ex2);
    } else if (element == "!=") {
        assignedInReverse(ex1, ex2);
        return new NotEqual(ex1, ex2);
    } else {
        return new Number(element);
    }
}

Expression *ExpresionFactory::operator()(string infix) {
    replaceVar(infix);
    this->shuntingYard(infix);
    Expression *answer = postfixToExpression();
    if (!postfix.empty()) {
        throw SYNTAX_ERROR;
    }
    return answer;

}

void ExpresionFactory::assignedInReverse(Expression *&ex1, Expression *&ex2) {
    ex2 = postfixToExpression();
    ex1 = postfixToExpression();

}

bool ExpresionFactory::isNeg(char c, int i, string expression) {
    if (c == '-') {
        if (i == 0) {
            return true;
        }
        char pre_c = expression[i - 1];
        return !((pre_c >= '0' && pre_c <= '9') || pre_c == ')');
    }
    return false;

}

void ExpresionFactory::replaceVar(string &expression) {
    vector<string> symbols = tables.getVarSymbols();
    double value;
    Expression *ex;

    for (vector_iterator it = symbols.begin(); it != symbols.end(); ++it) {
        ex = tables.getEx(it);
        value = ex->calculate();
        replaceSubstring(expression, *it, to_string(value));
    }
}

void ExpresionFactory::replaceSubstring(string &ori, const string &search, const string &replace) const {
    size_t pos = 0;
    while ((pos = ori.find(search, pos)) != string::npos) {
        ori.replace(pos, search.length(), "(" + replace + ")");
        pos += replace.length() + 2;
    }

}

ExpresionFactory::ExpresionFactory(SymbolTable &tables) : tables(tables) {}

bool ExpresionFactory::isTwoCharOperator(string operator_str, string expression, int i) {
    if (i != expression.size() - 1 && (operator_str == ">" || operator_str == "<" || operator_str == "=")) {
        return expression[i + 1] == '=';
    }
    return false;
}

void ExpresionFactory::dealWithOperator(string new_operator, string expression, stack<string> *operators, int &i,
                                        int &counter) {
    if (isTwoCharOperator(new_operator, expression, i)) {
        i++;
        new_operator += expression[i];
    }
    //while there is a precedence operator in the stack move it to the postfix
    while (isFirstPrecedenceBigger(*operators, new_operator)) {
        postfix.push_back(operators->top());
        counter++;
        operators->pop();
    }
    operators->push(new_operator);
}

