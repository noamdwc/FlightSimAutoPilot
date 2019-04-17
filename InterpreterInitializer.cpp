//
// Created by to on 12/21/18.
//

#include "InterpreterInitializer.h"

#define NEW_VAR_SYMBOL "var"
#define PRINT "print"
#define IF_SYMBOL "if"
#define WHILE_SYMBOL "while"
#define OPED_DATA_SYMBOL "openDataServer"
#define CONNECT_SYMBOL "connect"
#define SLEEP_SYMBOL "sleep"
#define ENTER_SYMBOL "Enterc"


void InterpreterInitializer::initialize() {
    //basic commands
    SleepCommand *sleep_command = new SleepCommand(ex_factory);

    VarAssignCommand *var_assign_command = new VarAssignCommand(ex_factory, st);

    PrintCommand *print_command = new PrintCommand(ex_factory, st);

    OpenDataServerCommand *open_server_command = new OpenDataServerCommand(ex_factory, st);

    ConnactCommand *connect_command = new ConnactCommand(ex_factory, st);

    //new var command that need var assign command
    NewVarCommand *new_var_command = new NewVarCommand(ex_factory, st, var_assign_command);

    //add commands to table
    st.addCommand(SLEEP_SYMBOL, sleep_command);
    st.addCommand(OPED_DATA_SYMBOL, open_server_command);
    st.addCommand(CONNECT_SYMBOL, connect_command);
    st.addCommand(NEW_VAR_SYMBOL, new_var_command);
    st.addCommand(PRINT, print_command);
    //create parser
    SymbolTable *st_ptr = &st;
    Parser *parser = new Parser(var_assign_command, st_ptr);

    //create lexer
    lexer = new Lexer(parser);

    //stream needed commands
    if (is_from_file) {
        EnterCommand *enter_command = new EnterCommand(stream);
        st.addCommand(ENTER_SYMBOL, enter_command);
        stream_setables.push_back(enter_command);
        FuncCommandFactory *func_factory = new FuncCommandFactory(this, stream);
        factory_to_del = func_factory;
        IfCommand *if_command = new IfCommand(ex_factory, *func_factory);
        WhileCommand *while_command = new WhileCommand(ex_factory, *func_factory);
        st.addCommand(IF_SYMBOL, if_command);
        stream_setables.push_back(if_command);
        st.addCommand(WHILE_SYMBOL, while_command);
        stream_setables.push_back(while_command);
    } else {
        istream *is = &cin;
        EnterCommand *enter_command = new EnterCommand(is);
        st.addCommand(ENTER_SYMBOL, enter_command);
        stream_setables.push_back(enter_command);
        FuncCommandFactory *func_factory = new FuncCommandFactory(this, is);
        factory_to_del = func_factory;
        IfCommand *if_command = new IfCommand(ex_factory, *func_factory);
        WhileCommand *while_command = new WhileCommand(ex_factory, *func_factory);
        st.addCommand(IF_SYMBOL, if_command);
        stream_setables.push_back(if_command);
        st.addCommand(WHILE_SYMBOL, while_command);
        stream_setables.push_back(while_command);

    }


}

void InterpreterInitializer::initializeNewStream(istream *stream) {
    vector<StreamSetable *>::iterator it;
    for (it = stream_setables.begin(); it != stream_setables.end(); ++it) {
        (*it)->setStream(stream);
    }
}

InterpreterInitializer::InterpreterInitializer(string path) : ex_factory(st) {
    if (path.empty()) {
        is_from_file = false;
    } else {
        stream = new ifstream(path);
        if (*stream) {

        }
        is_from_file = true;
    }
    initialize();
}

void InterpreterInitializer::start() {
    istream *is;
    if (is_from_file) {
        is = (istream *) stream;
        lexer->getInputs(is);
    } else {
        is = &cin;
        lexer->getInputs(is);
    }
}

bool InterpreterInitializer::isInExitMode() {
    return lexer->isInExitMode();
}

InterpreterInitializer::~InterpreterInitializer() {
    st.freeItAll();
    if (is_from_file) {
        stream->close();
        delete (stream);
    }
    delete (lexer);

    delete (factory_to_del);

}

SymbolTable &InterpreterInitializer::getTable() {
    return st;
}

Lexer *InterpreterInitializer::getLexer() {
    return lexer;
}

