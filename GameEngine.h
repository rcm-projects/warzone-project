// ------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
// ------------------------------------------

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include "Map.hpp"
#include "Player.h"
#include "Cards.h"

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
    
    //---------------------------------------------------------
    //             Game startup phase
    //---------------------------------------------------------
    
    // StartupPhase, load map, validate map, add player, distribute Territories, determine player order, draw cards
    void startupPhase ();
    void startupPhaseMenu();
    void loadmap(const string name);
    void validatemap();
    void addPlayer(const string name);
    void distributeTerritories();
    void giveArmies();
    void determinePlayOrder();
    void drawInitialCards();

private:
    map<string, vector<string>>* states;
    Map gameMap;
    vector <Player*> players;
    Deck* deck;
};
