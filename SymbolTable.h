//
// Created by to on 12/17/18.
//

#ifndef FLIGHTSIMULATO_SYMBOLTABLE_H
#define FLIGHTSIMULATO_SYMBOLTABLE_H

#include <unordered_map>
#include "Expression/CommandExpression.h"
#include "ErrorMessages.h"
#include "Client.h"
#include "Expression/Number.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include "ExitMode.h"


#define SERVER_VARS {"\"/instrumentation/airspeed-indicator/indicated-speed-kt\"","\"/instrumentation/altimeter/indicated-altitude-ft\"","\"/instrumentation/altimeter/pressure-alt-ft\"","\"/instrumentation/attitude-indicator/indicated-pitch-deg\"","\"/instrumentation/attitude-indicator/indicated-roll-deg\"","\"/instrumentation/attitude-indicator/internal-pitch-deg\"","\"/instrumentation/attitude-indicator/internal-roll-deg\"","\"/instrumentation/encoder/indicated-altitude-ft\"","\"/instrumentation/encoder/pressure-alt-ft\"","\"/instrumentation/gps/indicated-altitude-ft\"","\"/instrumentation/gps/indicated-ground-speed-kt\"","\"/instrumentation/gps/indicated-vertical-speed\"","\"/instrumentation/heading-indicator/indicated-heading-deg\"","\"/instrumentation/magnetic-compass/indicated-heading-deg\"","\"/instrumentation/slip-skid-ball/indicated-slip-skid\"","\"/instrumentation/turn-indicator/indicated-turn-rate\"","\"/instrumentation/vertical-speed-indicator/indicated-speed-fpm\"","\"/controls/flight/aileron\"","\"/controls/flight/elevator\"","\"/controls/flight/rudder\"","\"/controls/flight/flaps\"","\"/controls/engines/current-engine/throttle\"","\"/engines/engine/rpm\""}

class SymbolTable : public ExitMode {
    //table for variables
    unordered_map<string, double> *var_table;
    //table for all commands
    unordered_map<string, Command *> *command_table;
    //saving the binded variables, the value is the var they the key is binded to.
    unordered_map<string, string> *binds;
    //table for all vars that are updated in the server
    unordered_map<string, double> *server_table;
    //this vector is used to free the memory of expression that are created
    vector<Expression *> *del_ex;
    vector<Command *> *del_command;
    vector<Client *> *clients;
    volatile bool *is_server_open;
    deque<string> *updates;
    pthread_mutex_t *mutex;
    vector<int> *sockets;
    volatile bool *is_in_exit_mode;

public:

    /**
     * bind a symbol to an expression
     * @param symbol  - the symbol to bind
     * @param bind_with  0 the symbol to bind with
     */
    void bind(string symbol, string bind_with);

    /**
     * add an Expression to the map.
     * if the Expression is already in the map, overwrite it
     * this is only variable Expression, Commands will be given in the constructor only.
     * @param symbol - the Expression symbol
     * @param ex - the pointer to the Expression
     */
    void setEx(string symbol, Expression *ex);

    SymbolTable();

    /**
     * get an Expression from the table
     * @param it - an iterator the point to the symbol
     * @return -  the expression with the symbol the iterator point on or null if the Expression is not in the table
     */
    Expression *getEx(const vector_iterator &it);


    /**
     * free all the memory for the Expressions adn Commands
     */
    ~SymbolTable();

    /**
     * get all the symbols of variables
     * @return - a vector of all the symbols of all the variables
     */
    vector<string> getVarSymbols();


    /**
     * check if a given string is a symbol of a command
     * @param symbol - the given string
     * @return true is the symbol is a symbol of command, false otherwise
     */
    bool isCommandSymbol(string symbol);


    /**
     * add a command to the map
     * @param symbol - the symbol of the map
     * @param command - a pointer to the command
     */
    void addCommand(string symbol, Command *command);


    /**
     * add a command to v=be deleted at the end of the progrem
     * @param c_ptr - a pointer to the command to del
     */
    void addCommandToDel(Command *c_ptr);

    /**
     * free al the alocated memory
     */
    void freeItAll();

    /**
     * add a given client to the list of clients that inform when the table is changed
     * @param client - the given client
     */
    void addClient(Client *client);

    /**
     * update the server about a change
     * @param symbol - the value of the var that was changed
     * @param new_value - the new value of the var
     */
    void addUpdate(string symbol, Expression *new_value);

    /**
     * update a var from the server
     * @param symbol - the symbol of the var
     * @param new_value - the var new value
     */
    void updateFromServer(string symbol, double new_value);

    /**
     * checks if variable name is valid: not starting with number or symbols(except _ and $),
     * @param str
     * @return true if valid, false if not.
     */
    bool isNameValid(string str);

    /**
     * get the string of the symbol the symbol is bind to. if there is'nt any return the symbol
     * @param symbol - the given symbol
     * @return string of the symbol the symbol is bind to
     */
    string getBinedSymbol(string symbol);

    bool isServerOpen() const;

    /**
     * set the bool to true
     */
    void severOpened();

    /**
     * set the bool to false
     */
    void severClosed();



    /**
     * send all the updates to the server
     */
    void sendUpdates();

    /**
     * used for tests, print all the variables
     */
    void printItAll();

    /**
     * add a socket to the vector of socket to close at the end of the program
     * @param sockid - the id for the socket to add
     */
    void addSocket(int sockid);

    bool isInExitMode() override;

    /**
     * lock mutex
     */
    void lockMutex();

    /**
     * unlock mutex
     */
    void unlcokMutex();

private:
    /**
     *
     * @param ch
     * @return true if ch is a letter, false if it's anything else
     */
    bool isLetter(char ch);

    /**
     * create an Expression from a given number
     * @param num - the given number
     * @return expression of the number (meaning the expression.caculate()= num)
     */
    Expression *numToExpression(double num);
};


#endif //FLIGHTSIMULATO_SYMBOLTABLE_H
