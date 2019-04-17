//
// Created by nikol on 12/18/18.
//

#ifndef FLIGHTSIMULATO_PARSER_H
#define FLIGHTSIMULATO_PARSER_H

#include "SymbolTable.h"
#include "ErrorMessages.h"
#include <vector>

class Parser {

    Command *defult_command;

    SymbolTable *_database;
public:
    Parser(Command *defaultCommand, SymbolTable *&_database);

    /**
     * execute the line
     * @param line
     */
    void parse(vector<string> line);

    virtual ~Parser();

    SymbolTable &getTable();

private:

    /**
 * creates a vector that hold each argument as element (example: 5+2 is one element)
 * throws SYNTAX_EXCEPTION
 * @param line
 * @return vector<string> processed line
 */
    vector<string> processLine(vector<string> line);



    /**
     *
     * @param s
     * @return true is a represents a number, false otherwise.
     */
    bool isNumber(string s);

    /**
     *
     * @param s
     * @return true if s is an operator, false otherwise
     */
    bool isOperator(string s);

    /**
     * add to string elements from vector until
     * @param it - an iterator to vector of string toget strings form
     * @param end - the iterator to the end of the vector
     * @param add_to - the string to add to
     * @param end_at - the char to end at
     * @return how much elements from the vector were used
     */
    int addUntilChar(vector_iterator it, vector_iterator end, string &add_to, string end_at);


};


#endif //FLIGHTSIMULATO_PARSER_H
