
#include "Player.h"

using namespace std;

//defualt constructor
Player::Player() {
   string name;
	vector<string*> terriorty;
	vector<string*> handCard;
	vector<Order*> orderList;
}

// Parameterized constructor
Player::Player(string* name, vector<string*> t, vector<string*> h, vector<Order*> o) 
{
    this->name = name;           
    this->terriorty = t;                           
    this->handCard = h;                           
    this->orderList = o;                           
}

// Copy constructor
Player::Player(const Player& p) 
{
    name = new string(*p.name);                   
    terriorty = p.terriorty;                       // shallow copy territories
    handCard = p.handCard;                    
    orderList = vector<Order*>();    // initialize a new vector for orders

    // Deep copy of orderList
    for (Order* order : p.orderList) {
        orderList.push_back(new Order(*order));     //
  }}


// Destructor
Player::~Player()
{
    name.clear();                                
    for (auto territory : terriorty) {
        delete territory;             // free each territory string pointer
    }
    terriorty.clear();                         
    for (auto card : handCard) {
        delete card;            // free each hand card string pointer
    }
    handCard.clear();               
    for (auto order : orderList) {
        delete order;       
    }
    orderList.clear();         // Clear orders vector
}


// Print territories to attack
void Player::toAttack() 
{
    cout << "Territories to attack: ";
    for (int i = 0; i < terriorty.size(); i++) 
    {
        cout << *terriorty[i] << " ";  //assuming territory names: stored as strings
    }
    cout << endl;
}



void Player::toDefend() 
{
    cout << "Territories to defend: ";
    for (int i = 0; i < terriorty.size(); i++)
    {
        cout << *terriorty[i] << " ";             
    }
     cout << endl

}

// Issue a new order
void Player::issueOrder(string order) 
{
    Order* a = new Order(order);                  // create a new Order
    orderList.push_back(a);                       //add to the order list
}


// Get the list of orders
vector<Order*> Player::getOrderList() 
{
    return orderList;          // return the order list
}

// Print all orders
void Player::printOrder() 
{
    cout << "Orders: ";
    for (auto order : orderList) 
    {
        cout << order->getResult() << " ";      
    }
    cout << endl;
}