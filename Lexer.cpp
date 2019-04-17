//
// Created by noamdwc to on 12/12/18.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Lexer.h"

vector<string> Lexer::splitLine(string &line) const {
    vector<string> answer;
    string part;
    string c;
    prepareToSplit(line);
    for (int i = 0; i < line.size(); ++i) {
        c = line[i];
        if (c == SEPARATOR) {
            if (!part.empty()) {
                answer.push_back(part);
            }
            part = "";
            continue;
        }
        part += line[i];
    }
    if (!part.empty()) {
        answer.push_back(part);
    }
    return answer;
}

void Lexer::getInputs(istream *&input_stream) {
    string input;
    unsigned int line_num = 0;
    //if the input is exit, stop getting inputs
    while (getline(*input_stream, input)&&!is_in_exit_mode) {
        if (input == EXIT) {
            is_in_exit_mode = true;
            break;
        }
        //if the input is not empty
        if (input != "") {
            line_num++;
            vector<string> parts = splitLine(input);
            try {
                lexingOneLine(input);
            } catch (char const *&error_massage) {
                cout << "error in line " << line_num << ":" << error_massage << endl;
                break;
            } catch (exception &e) {
                cout << "an error has accord" << endl;
            }
        }
        //send updates to server
        parser->getTable().sendUpdates();
    }

}

void Lexer::prepareToSplit(string &line) const {
    string answer;
    vector<string> special_operators = SPECIAL_OPERATOR;
    bool is_in_quotation = false;
    string character;
    string::iterator it;
    for (it = line.begin(); it != line.end(); ++it) {
        character = *it;
        if (character == "\"") {
            is_in_quotation = !is_in_quotation;
            answer += character;
            continue;
        }
        if ((find(special_operators.begin(), special_operators.end(), character) != special_operators.end()) &&
            !is_in_quotation) {
            string to_replace = " " + character + " ";
            answer += to_replace;
        } else {
            answer += character;
        }
    }
    line = answer;

}

void Lexer::lexingOneLine(string line) {
    vector<string> parts = splitLine(line);
    parser->parse(parts);
}

Lexer::Lexer(Parser *parser) : parser(parser) {
    is_in_exit_mode = false;
}

Lexer::~Lexer() {
    delete (parser);
}

SymbolTable &Lexer::getTable() const {
    return parser->getTable();
}

bool Lexer::isInExitMode() {
    return is_in_exit_mode;
}



