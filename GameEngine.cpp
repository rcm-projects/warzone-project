// ------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
// ------------------------------------------


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "GameEngine.h"
#include "Map.hpp"
#include "Player.h"
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

//---------------------------------------------------------
//             Game startup phase
//---------------------------------------------------------

// StartupPhase method
void GameEngine::startupPhase (){
    string command;
    int countPlayer = 0;
        
    while (command != "gamestart"){
        startupPhaseMenu();
        cout << "Enter command: ";
        cin >> command;
        
        if (command == "loadmap" | command == "1"){
            cout << "Choose map from available list:\n";
            cout << "USA, Africa, Alberta.\n";
            string map;
            cin >> map;
            loadmap(map);
        } else if (command == "validatemap"  | command == "2"){
            validatemap();
        } else if (command == "addplayer"  | command == "3"){
            if (countPlayer <= 6) {
                cout << "Enter player name: ";
                string input;
                cin >> input;
                addPlayer(input);
                countPlayer++;
            } else {
                cout << "Sorry, you’ve reached the maximum number of players allowed.";
            }
        } else if (command == "gamestart" | command == "4"){
            distributeTerritories();
            giveArmies();
            drawInitialCards();
            //playPhase();
        } else if (command == "exit" | command == "5") {
            break;
        } else {
            cout << "Invalid command. Try again.\n";
        }
    }
}

// Display Startup Phase Menu
void GameEngine::startupPhaseMenu(){
    cout << "========= Startup Phase =========\n";
    cout << "Available commands:\n";
    cout << "1) loadmap <filename> - Load a map from the available maps.\n";
    cout << "2) validatemap - Validate the loaded map.\n";
    cout << "3) addplayer <playername> - Add a player to the game (2-6 players).\n";
    cout << "4) gamestart - Start the game when all setup is complete.\n";
    cout << "5) exit - Quit the game.\n";
    cout << "======================================\n";
}

// load map
void GameEngine::loadmap(const string name){
    MapLoader loader;
    gameMap = loader.loadMap(name);
    cout <<"\n";
    cout << "The map being loaded!\n";
}

// validate map
void GameEngine::validatemap(){
    if (gameMap.validate()) {
        cout << "The map is valid!\n" << endl;
    } else {
        cout << "The map has issues.\n" << endl;
    }
}

// add player
void GameEngine::addPlayer(const string name){
    Player* newPlayer = new Player();//change bc players needs to be a vector of pointers
    newPlayer->setName(name);
    players.push_back(newPlayer);
    cout << "A new player has been added!\n";
    cout << "The current players are: \n";
    for (const auto& gamer : players) {
        cout << gamer->getName() << "\n";
    }
}

// distribute territories
void GameEngine::distributeTerritories() {
    size_t numPlayers = players.size();
    size_t numTerritories = gameMap.territories.size();

    if (numPlayers == 0) {
        std::cerr << "Error: No players available to assign territories.\n";
        return;
    }

    if (numTerritories == 0) {
        std::cerr << "Error: No territories available to distribute.\n";
        return;
    }

    // Distribute territories in a round-robin fashion
    for (size_t i = 0; i < numTerritories; ++i) {
        size_t playerIndex = i % numPlayers;

        players[playerIndex]->addTerritory(gameMap.territories[i].getName());
        std::cout << "Assigned territory " << gameMap.territories[i].getName()
                  << " to player " << players[playerIndex]->getName() << ".\n";
    }
    std::cout << "Territory distribution complete.\n";
}

// give army
void GameEngine::giveArmies(){
    size_t numPlayers = players.size();
        for (size_t i = 0; i < numPlayers; i++) {
            players[i]->setArmies(50);
            cout << "Player " << players[i]->getName() << " received 50 army units.\n";  
        }
}

//determine player order
void GameEngine::determinePlayOrder() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(players.begin(), players.end(), rng);
    std::cout << "Randomized order of play:" << std::endl;
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << "Player " << players[i]->getName() << " will play in position " << (i + 1) << std::endl;
    }
}

// draw cards
void GameEngine::drawInitialCards() {
    Deck* deck = new Deck;
    for (Player* player : players) {
            for (int i = 0; i < 2; ++i) {
                Card* drawnCard = deck->draw();
                if (drawnCard) {
                    player->getHandCards()->AddCardToHand(drawnCard);
                    player->getHandCards()->ShowCardInHand();
                } else {
                    cout << "The deck is empty; cannot draw more cards." << endl;
                    break;
                }
            }
        }
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
