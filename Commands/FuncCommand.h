//
// Created by to on 12/18/18.
//

#ifndef FLIGHTSIMULATO_PATCHCODECOMMAND_H
#define FLIGHTSIMULATO_PATCHCODECOMMAND_H

#include <iostream>
#include <algorithm>
#include "../Lexer.h"
#include "ArgumentsHandlerCommand.h"
#include "../Initializer.h"
#include "../ExitMode.h"

class FuncCommand : public Command, public ExitMode {
    Initializer* initializer;
    istream *stream;
    vector<string> lines;
    bool is_open_at_frist_line;

public:
    /**
     *check if the program is in exit mode
     * @return true if the program is in exit true, false otherwise
     */
    bool isInExitMode() override;

    bool isOpenAtLine() const;

    FuncCommand(Initializer *initializer, istream *stream);


    int doCommand(vector_iterator it) override;

private:
    /**
     * get the lines of command to do when the function is activated
     */
    void getLinesFromStream();

    /**
     * check if this is the end of the codes part
     * @return true if this is the end othedoe, false otherwise
     */
    bool isEnd(string line);


    /**
     * convert lines to one string with "\n"
     * @return lines as one string
     */
    string vectorToString();


};


#endif //FLIGHTSIMULATO_PATCHCODECOMMAND_H
