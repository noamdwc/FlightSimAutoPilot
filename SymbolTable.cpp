//
// Created by to on 12/17/18.
//

#include "SymbolTable.h"
#include "iostream"


void SymbolTable::setEx(string symbol, Expression *ex) {
    lockMutex();
    //check if var name(symbol) is valid
    if (!isNameValid(symbol)) {
        delete (ex);
        unlcokMutex();
        throw SYNTAX_ERROR;
    }
    //check the binds table
    symbol = getBinedSymbol(symbol);
    if (server_table->find(symbol) != server_table->end()) {
        addUpdate(symbol, ex);
        server_table->operator[](symbol) = ex->calculate();
        del_ex->push_back(ex);
        unlcokMutex();
        return;
    }
    if (isCommandSymbol(symbol)) {
        delete (ex);
        unlcokMutex();
        throw SYNTAX_ERROR;
    }
    del_ex->push_back(ex);
    unlcokMutex();
    var_table->operator[](symbol) = ex->calculate();
}

Expression *SymbolTable::getEx(const vector_iterator &it) {
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mutex);
    string symbol = *it;
    //check the binds table
    symbol = getBinedSymbol(symbol);

    //check Command table
    if (command_table->find(symbol) != command_table->end()) {
        Command *c = command_table->operator[](symbol);
        CommandExpression *c_ex = new CommandExpression(c, it + 1);
        del_ex->push_back(c_ex);
        pthread_mutex_unlock(&mutex);
        return c_ex;
    }
    //check Expression table,
    if (var_table->find(symbol) != var_table->end()) {
        pthread_mutex_unlock(&mutex);
        return numToExpression(var_table->operator[](symbol));
    }
    //check server var table,
    if (server_table->find(symbol) != server_table->end()) {
        pthread_mutex_unlock(&mutex);
        return numToExpression(server_table->operator[](symbol));
    }
    // if in none of them, return null
    pthread_mutex_unlock(&mutex);
    return NULL;
}

SymbolTable::~SymbolTable() {}

SymbolTable::SymbolTable() {
    var_table = new unordered_map<string, double>;
    del_ex = new vector<Expression *>;
    del_command = new vector<Command *>;
    command_table = new unordered_map<string, Command *>;
    binds = new unordered_map<string, string>;
    server_table = new unordered_map<string, double>;
    clients = new vector<Client *>;
    sockets = new vector<int>;

    //add the values for the server var
    vector<string> server_vars = SERVER_VARS;
    for (vector_iterator it = server_vars.begin(); it != server_vars.end(); ++it) {
        server_table->operator[](*it) = 0;
    }
    is_server_open = new bool;
    is_in_exit_mode = new bool;
    (*is_server_open) = false;
    (*is_in_exit_mode) = false;

    updates = new deque<string>;

    mutex = new pthread_mutex_t(PTHREAD_MUTEX_INITIALIZER);

}

bool SymbolTable::isServerOpen() const {
    return *is_server_open;
}


vector<string> SymbolTable::getVarSymbols() {
    vector<string> answer;
    unordered_map<string, double>::iterator it_ex;
    for (it_ex = var_table->begin(); it_ex != var_table->end(); ++it_ex) {
        answer.push_back(it_ex->first);
    }
    unordered_map<string, string>::iterator it_str;
    for (it_str = binds->begin(); it_str != binds->end(); ++it_str) {
        answer.push_back(it_str->first);
    }
    for (it_ex = server_table->begin(); it_ex != server_table->end(); ++it_ex) {
        answer.push_back(it_ex->first);
    }
    return answer;
}

bool SymbolTable::isCommandSymbol(string symbol) {
    vector<string> answer;
    unordered_map<string, Command *>::iterator it;
    for (it = command_table->begin(); it != command_table->end(); ++it) {
        if (symbol == (*it).first) {
            return true;
        }
    }
    return false;

}

void SymbolTable::bind(string symbol, string bind_with) {
    vector<string> vars = getVarSymbols();
    binds->operator[](symbol) = bind_with;
    //check if bind_with doesn't has a value
    if (find(vars.begin(), vars.end(), bind_with) == vars.end() && binds->find(bind_with) == binds->end()) {
        string dummy_zero = "0";
        server_table->operator[](bind_with) = 0;
        Number temp(0);
        addUpdate(bind_with, &temp);
    }

}

void SymbolTable::addCommand(string symbol, Command *command) {
    command_table->operator[](symbol) = command;
}

void SymbolTable::addCommandToDel(Command *c_ptr) {
    del_command->push_back(c_ptr);
}

void SymbolTable::freeItAll() {
    (*is_in_exit_mode) = true;
    while (!is_server_open) {}
    unordered_map<string, Command *>::iterator it_c;
    vector<Expression *>::iterator it_exc;
    vector<Command *>::iterator it_cv;
    vector<Client *>::iterator it_client;
    vector<int>::iterator it_int;
    for (it_c = command_table->begin(); it_c != command_table->end(); ++it_c) {
        delete ((*it_c).second);
    }
    for (it_exc = del_ex->begin(); it_exc != del_ex->end(); ++it_exc) {
        delete (*it_exc);
    }
    for (it_cv = del_command->begin(); it_cv != del_command->end(); ++it_cv) {
        delete (*it_cv);
    }
    for (it_client = clients->begin(); it_client != clients->end(); ++it_client) {
        delete (*it_client);
    }
    for (it_int = sockets->begin(); it_int != sockets->end(); ++it_int) {
        close(*it_int);
    }

    delete (clients);
    delete (var_table);
    delete (command_table);
    delete (del_ex);
    delete (binds);
    delete (del_command);
    delete (server_table);
    delete (is_server_open);
    delete (updates);
    delete (mutex);
    delete (sockets);
    delete (is_in_exit_mode);
}

void SymbolTable::addClient(Client *client) {
    clients->push_back(client);
    sockets->push_back(client->getSockfd());
}

void SymbolTable::addUpdate(string symbol, Expression *new_value) {
    string msg = "set " + symbol.substr(1, symbol.size() - 2) + " " + to_string(new_value->calculate()) + "\r\n";
    updates->push_back(msg);
}

void SymbolTable::updateFromServer(string symbol, double new_value) {
    server_table->operator[](symbol) = new_value;
//    Number *value = new Number(new_value);
//    setEx(symbol, value);
}

bool SymbolTable::isNameValid(string str) {
    //has to be a word, but not saved word. so check in commands table if this word is a key
    for (unordered_map<string, Command *>::iterator itr = command_table->begin(); itr != command_table->end(); ++itr) {
        if (str == itr->first) {
            return false;
        }
    }
    if (str == "bind") {
        return false;
    }
    //check for quote (could be for paths in the simulator)
    if (str[0] == '"' && str[str.size() - 1] == '"') {
        if (str.size() > 1) {
            if (str[1] == '/') {
                string substr = str.substr(2, str.size() - 1);
                return true;
            }
        }
        return false;
    }
    //now we checked that str is not a saved word, check if it starts with a letter or '_'
    return isLetter(*str.begin()) || (*str.begin()) == '_';
}

bool SymbolTable::isLetter(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

string SymbolTable::getBinedSymbol(string symbol) {
    while (binds->find(symbol) != binds->end()) {
        //if found change the symbol
        symbol = binds->operator[](symbol);
    }
    return symbol;
}

void SymbolTable::severOpened() {
    (*is_server_open) = true;

}

void SymbolTable::printItAll() {
    vector<string> vars = getVarSymbols();
    for (vector_iterator it = vars.begin(); it != vars.end(); ++it) {
        cout << "(" + *it + "," + getEx(it)->toString() + ")" << endl;
    }

}

void SymbolTable::sendUpdates() {
    // there are clients to send throw
    if (!clients->empty()) {
        string msg;
        vector<Client *>::iterator it_client;
        while (!updates->empty()) {
            msg = updates->front();
            updates->pop_front();
            for (it_client = clients->begin(); it_client != clients->end(); ++it_client) {
                (*it_client)->sendMsg(msg);
            }
        }
    }

}


Expression *SymbolTable::numToExpression(double num) {
    Expression *ex = new Number(num);
    del_ex->push_back(ex);
    return ex;
}

void SymbolTable::addSocket(int sockid) {
    sockets->push_back(sockid);
}

bool SymbolTable::isInExitMode() {
    return (*is_in_exit_mode);
}

void SymbolTable::severClosed() {
    (*is_server_open) = false;
}

void SymbolTable::lockMutex() {
    pthread_mutex_lock(mutex);

}

void SymbolTable::unlcokMutex() {
    pthread_mutex_unlock(mutex);
}

