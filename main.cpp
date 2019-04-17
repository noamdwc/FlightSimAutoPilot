#include <iostream>
#include <fstream>
#include "Parser.h"
#include "InterpreterInitializer.h"

using namespace std;


int main(int argc, char** argv) {
if (argc == 1) {
    InterpreterInitializer init("");
    init.start();
} else{
    string path(*(argv+1));
    InterpreterInitializer init(path);
    init.start();
}


}
