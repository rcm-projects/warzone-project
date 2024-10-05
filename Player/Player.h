#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "../Orders.h"  // Include Orders.h for Order-related classes

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

private:
    string name;                   // Name of the player
    vector<string> territory;
    vector<string> handCard;
    vector<Order*> orderList;
};

#endif 