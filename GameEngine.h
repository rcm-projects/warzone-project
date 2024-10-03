// ------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
// ------------------------------------------

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class GameEngine {
public:
    // Default constructor
    GameEngine();

    // Copy constructor
    GameEngine(const GameEngine& other);

    // Assignment operator
    GameEngine& operator=(const GameEngine& other);

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const GameEngine& engine);

	void Run();

	string CommandToState(string currentState, string commandRequest);

private:
    map<string, vector<string>>* states;

};