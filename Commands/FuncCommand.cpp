//
// Created by to on 12/18/18.
//

#include <sstream>
#include "FuncCommand.h"


void FuncCommand::getLinesFromStream() {
    string line;
    int closer_counter = 0;

    //take care of the first line (can have ( at the start)
    getline(*stream, line);
    if (line[0] == '{') {
        line = line.substr(1, line.size() - 1);
        is_open_at_frist_line = true;
    }
    //if the line is not empty
    if (!line.empty()) {
        if (line[0] == '{' || line[line.size() - 1] == '{') {
            closer_counter++;
        }
        lines.push_back(line);
    }
    if (!isEnd(line)) {
        while (getline(*stream, line)) {
            //check if end the loop
            if (isEnd(line)) {
                //remove the "}"
                if (closer_counter == 0) {
                    line = line.substr(0, line.size() - 1);
                    if (!line.empty()) {
                        lines.push_back(line);
                    }
                    break;
                }
                closer_counter--;
            }

            //if the line is not empty
            if (!line.empty()) {
                if (line[0] == '{' || line[line.size() - 1] == '{') {
                    closer_counter++;
                }
                lines.push_back(line);
            }
        }
    }

}

int FuncCommand::doCommand(vector_iterator it) {
    int counter = 0;
    string lines_str = vectorToString();
    istream *new_stream = new istringstream(lines_str.c_str());
    initializer->initializeNewStream(new_stream);
    initializer->getLexer()->getInputs(new_stream);
    if (!is_open_at_frist_line) {
        counter++;
    }
    initializer->initializeNewStream(stream);
    delete (new_stream);
    return counter;

}

bool FuncCommand::isEnd(string line) {
    return line[line.size() - 1] == '}';
}


bool FuncCommand::isOpenAtLine() const {
    return is_open_at_frist_line;
}

FuncCommand::FuncCommand(Initializer *initializer, istream *stream) : initializer(initializer), stream(stream) {
    is_open_at_frist_line = false;
    getLinesFromStream();
}

string FuncCommand::vectorToString() {
    string answer;
    if (!lines.empty()) {
        answer = lines[0];
        for (vector_iterator it = lines.begin() + 1; it != lines.end(); ++it) {
            answer += "\n" + *it;
        }
    }
    return answer;
}

bool FuncCommand::isInExitMode() {
    return initializer->isInExitMode();
}
