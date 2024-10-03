// ------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
// ------------------------------------------


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "GameEngine.h"
using namespace std;

    // Default Constructor
    GameEngine::GameEngine() {
        states = new map<string, vector<string>>();
    }

    // Copy constructor
    GameEngine::GameEngine(const GameEngine& other) {
        states = other.states;
    }

    // assignment operator
    GameEngine& GameEngine::operator=(const GameEngine& other) {
        if (this == &other) return *this; // Self-assignment check

        // Clean up existing state
        delete states;

        // Deep copy the other object's states
        states = new map<string, vector<string>>(*other.states);

        return *this;
    }

    // stream insertion operator
    ostream& operator<<(ostream& os, const GameEngine& engine) {
        os << "GameEngine States:\n";
        for (const auto& state : *engine.states) {
            os << "State: " << state.first << "\nCommands: ";
            for (const auto& command : state.second) {
                os << command << " ";
            }
            os << "\n";
        }
        return os;
    }


    void GameEngine::Run() {

        // use map with string key and vector value to store states and valid commands

        (*states)["start"] = { "loadmap" };
        (*states)["map loaded"] = { "loadmap" , "validatemap" };
        (*states)["map validated"] = { "addplayer" };
        (*states)["players added"] = { "addplayer", "assigncountries" };
        (*states)["assign reinforcement"] = { "issueorder" };
        (*states)["issue orders"] = { "issueorder", "endissueorders" };
        (*states)["execute orders"] = { "execorder", "endexecorders", "win" };
        (*states)["win"] = { "end", "play" };

        // initialize to start
        string currentState = "start";
        // set bool for loop
        bool endGame = false;

        // Loop until end is reached, allow player to continue changing states.
        while (endGame == false) {

            cout << "\nCurrent state: " << currentState << endl << "Available Commands:\n";

            for (const string& command : (*states).at(currentState)) {
                cout << command << "\n";
            }

            string commandRequest;

            cout << "\nEnter a command: ";
            cin >> commandRequest;

            bool isValidCommand = false;

            for (const string& command : (*states).at(currentState)) {
                if (commandRequest == command)
                    isValidCommand = true;
            }

            if (isValidCommand == true) {
                // switch currentstate to whatever state that commands points to
                currentState = CommandToState(currentState, commandRequest);

                // end game if user wants to, and is a valid command
                if (commandRequest == "end")
                    endGame = true;
            }
            else
            {
                cout << "\nInvalid command. Try Again.\n";
            }

        }

        delete states;

    }

    string GameEngine::CommandToState(string currentState, string commandRequest) {
        if (currentState == "start") {
            if (commandRequest == "loadmap") {
                currentState = "map loaded";
            }
        }
        else if (currentState == "map loaded") {
            if (commandRequest == "validatemap") {
                currentState = "map validated";
            }
            else if (commandRequest == "loadmap") {
                // Remain in "map loaded"
            }
        }
        else if (currentState == "map validated") {
            if (commandRequest == "addplayer") {
                currentState = "players added";
            }
        }
        else if (currentState == "players added") {
            if (commandRequest == "addplayer") {
                // Stay in "players added"
            }
            else if (commandRequest == "assigncountries") {
                currentState = "assign reinforcement";
            }
        }
        else if (currentState == "assign reinforcement") {
            if (commandRequest == "issueorder") {
                currentState = "issue orders";
            }
            else if (commandRequest == "endexecorders") {
                currentState = "execute orders";
            }
        }
        else if (currentState == "issue orders") {
            if (commandRequest == "issueorder") {
                // Stay in "issue orders"
            }
            else if (commandRequest == "endissueorders") {
                currentState = "execute orders";
            }
        }
        else if (currentState == "execute orders") {
            if (commandRequest == "execorder") {
                // Stay in "execute orders"
            }
            else if (commandRequest == "endexecorders") {
                currentState = "assign reinforcement";
            }
            else if (commandRequest == "win") {
                currentState = "win";
            }
        }
        else if (currentState == "win") {
            if (commandRequest == "play") {
                currentState = "assign reinforcement";
            }
            else if (commandRequest == "end") {
                currentState = "end";
            }
        }
        return currentState;
    }



/*
All commands

loadmap
validatemap
addplayer
assigncountries
issueorder
endissueorders
execorder
endexecorders
win
end
play 
*/