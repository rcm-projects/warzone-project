#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

// TODO: update includes when add your folders ...

#include "../Map.h"  
#include "../Orders.h"     
#include "../Cards.h"      

 #include "../OrderPTest.h"


using namespace std;

class player{

public:
 // Constructors
Player();    
Player(string name, vector<string*> t, vector<string*> h, vector<Order*> o);  
Player(const Player& p);    
 ~Player();                 // Destructor


// Methods 
 void toAttack();         // Print territories to attack
 // vector<string>* toDefend();  
 void toDefend();            // Print territories to defend
 void issueOrder(string order);    // Issue a new order
 vector<Order*> getOrderList();      // Get the list of orders
 void printOrder();           // Print all orders


private:

 string* name;        // name of the player (pointer)
 vector<string*> terriorty;    names
 vector<string*> handCard;      
 vector<Order*> orderList;     





};
#endif 