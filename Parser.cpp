//
// Created by nikol on 12/18/18.
//

#include "Parser.h"
#include <algorithm>

vector<string> Parser::processLine(vector<string> line) {
    vector_iterator it = line.begin();
    bool is_in_quotes = false;
    string temp = "";
    vector<string> res;
    while (it != line.end()) {
        //look at myself and the next string, add myself to temp and decide if im the last in sequence:
        //add temp to res and clear temp. if not:next string will be appended to me.
        //if im last: if im operator- throw. if I'm string/number add to temp and finish.
        temp += (*it);
        //number
        if (isNumber(*(it)) && !is_in_quotes) {
            //if next is not an operator or I'm the last element- Im last in the sequence.
            if ((it + 1) == line.end() || !isOperator(*(it + 1))) {
                res.push_back(temp);
                temp = "";
            }
        }
            //operator
        else if (isOperator(*it) && !is_in_quotes) {
            if ((it + 1) == line.end()) {
                throw SYNTAX_ERROR;
            }
            if (*(it + 1) == "=") {
                temp += "=";
                it++;
                if ((it + 1) == line.end()) {
                    throw SYNTAX_ERROR;
                }
            }
            //if next is not number or I'm last element, throw exception.
            if (!isNumber(*(it + 1))) {
                //check the spaicel case of operator before a neg number
                if (it + 2 != line.end() && *(it + 1) == "-") {
                    if (!isNumber(*(it + 2))) {
                        throw SYNTAX_ERROR;
                    }
                } else {
                    throw SYNTAX_ERROR;
                }
            }
        } else if ((*it) == "," && !is_in_quotes) {
            //delete myself from temp
            if (!temp.empty())
                temp.pop_back();
            //don't push empty string
            if (!temp.empty()) {
                res.push_back(temp);
            }
            temp = "";
        }
            // " : count the number of this symbol, if odd then there is a syntax error.
        else if ((*it) == "\"") {
            is_in_quotes = !is_in_quotes;
            if (!is_in_quotes) {
                res.push_back(temp);
                temp = "";
            }

        } else if ((*it) == "(") {
            it += addUntilChar(it + 1, line.end(), temp, ")");
            if ((it + 1) == line.end() || !isOperator(*(it + 1))) {
                res.push_back(temp);
                temp = "";
            }


        }
            //string
        else if (!is_in_quotes) {
            res.push_back(temp);
            temp = "";
        }
        it++;
    }
    return res;
}

bool Parser::isNumber(string s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit((*it))) {
        it++;
    }
    if (!s.empty() && it == s.end()) {
        return true;
    }
    vector<string> symbols = _database->getVarSymbols();
    return find(symbols.begin(), symbols.end(), s) != symbols.end();

}

bool Parser::isOperator(string s) {
    if (s.length() > 2)
        return false;
    else if (s.length() == 1) {
        char c = s[0];
        if (c == '*' || c == '/' || c == '+' || c == '-' || c == '<' || c == '>')
            return true;
    } else {
        char *c = (char *) s.c_str();
        //<= ,>= ,== or !=
        if ((c[1] == '=' && (c[0] == '<' || c[0] == '>' || c[0] == '=')) || (c[1] == '=' && c[0] == '!'))
            return true;
    }
    return false;
}

void Parser::parse(vector<string> line) {
    line = processLine(line);
    vector_iterator it = line.begin();
    //read first element in line and decide it's type: command or assignment
    if (_database->isCommandSymbol(*it)) {
        Expression *ex = _database->getEx(it);
        it += ex->calculate() + 1;
        //line should be empty now, if not empty throw syntax_error exception
        if (it != line.end())
            throw SYNTAX_ERROR;
    } else {
        defult_command->doCommand(it);
    }


}

Parser::Parser(Command *defaultCommand, SymbolTable *&_database) : defult_command(defaultCommand),
                                                                   _database(_database) {}

int Parser::addUntilChar(vector_iterator it, vector_iterator end, string &add_to, string end_at) {
    int counter = 0;
    while ((*it) != end_at) {
        if (it == end) {
            throw SYNTAX_ERROR;
        }
        add_to.append(*it);
        it++;
        counter++;
    }
    if (it == end) {
        throw SYNTAX_ERROR;
    }
    add_to.append(*it);
    it++;
    counter++;
    return counter;
}

SymbolTable &Parser::getTable() {
    return *_database;
}

Parser::~Parser() {
    delete (defult_command);
}


