//
// Created by noamdwc to on 12/12/18.
//

#ifndef FLIGHTSIMULATORPROJECT_LAXER_H
#define FLIGHTSIMULATORPROJECT_LAXER_H

#include <string>
#include <vector>
#include "Parser.h"
#include "ExitMode.h"


#define SEPARATOR " "
#define SPECIAL_OPERATOR {"+","-","*","/", "\"","<",">","<=",">=","==", "=" , "(" , ")"}
#define EXIT "exit"

using namespace std;


class Lexer : public ExitMode {
    Parser *parser;
    bool is_in_exit_mode;
public:

    virtual ~Lexer();

    Lexer(Parser *parser);


    /**
     * get the tables
     * @return the symbol tables that used by the parser
     */
    SymbolTable &getTable() const;


    /**
 * star waiting for comments, meaning running a loop to get input from the stream
 * @param input_stream - the stream from witch we get the input
 */
    void getInputs(istream *&input_stream);


    /**
     * lexing one line and send it to the parser
     * @param line - the line to lex and send to the parser
     * @return the output of the line from
     */
    void lexingOneLine(string line);


    /**
     * check if the program is in exit mode
     * @return
     */
    bool isInExitMode() override;


private:

    /**
     * prepare the string to be split by the SEPARATOR
     * @param line - the string to prepare
     */
    void prepareToSplit(string &line) const;


    /**
     * The function get a string iwth is a line in the code, and returns a vector of the string.
     * each element was seporated in the line by the separator
     * @param line  - the line from the consle/file as string
     * @return a vector of the parts of the line
     */
    vector<string> splitLine(string &line) const;


};


#endif //FLIGHTSIMULATORPROJECT_LAXER_H
