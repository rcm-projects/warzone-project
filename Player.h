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
    Player(const string& newName, const vector<string>& t, const vector<string>& h, const vector<Order*>& o);
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
    void addCardToHand(Card* card);
    void getHandCards() const;

private:
    int armies;
    string name;
    vector<string> territory;
    vector<string> handCard;
    vector<Order*> orderList;
    Hand* handCards;
};

#endif 
