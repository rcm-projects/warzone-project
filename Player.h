#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "Orders.h"  // Include Orders.h for Order-related classes
#include "Cards.h"

using namespace std;

class Player {
public:
    // Constructors
    Player();
    Player(const string& newName, const vector<string>& t, Hand* h, const vector<Order*>& o);
    Player(const Player& p);
    ~Player();                 // Destructor

    // Methods
    void toAttack() const;         // Print territories to attack
    void toDefend() const;         // Print territories to defend
    void issueOrder(const string& orderName); // Issue a new order based on a string
    vector<Order*> getOrderList() const;   // Get the list of orders
    void printOrder() const;       // Print all orders
    
    //---------------------------------------------------------
    //             Game startup phase
    //---------------------------------------------------------
    // methods used in startupPhase, name and armies
    string getName() const;
    void setName(const string& newName);
    void addTerritory(const string& territory);
    int getArmies() const;
    void setArmies(const int number);
    
    // cards
    Hand& getHandCards();

private:
    int armies;
    string name;
    vector<string> territory;
    //vector<string> handCard; //I don't think this needs to exist as it already exists in the class Hand and can be called through that
    //Please rearranged the overloaded constructors to work with the playerHand variable
    vector<Order*> orderList;
    Hand* playerHand;
};

#endif 
