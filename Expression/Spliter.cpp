//
// Created by to on 12/22/18.
//


#include "../Spliter.h"

vector<string> Spliter::split(string line, string seporator) {
    vector<string> answer;
    string part;
    string c;
    for (int i = 0; i < line.size(); ++i) {
        c = line[i];
        if (c == seporator) {
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
