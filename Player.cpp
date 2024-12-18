#include "Player.h"

// Default constructor
Player::Player() :name("Default"), playerHand(new Hand()) {}

//Parameterized constructor
Player::Player(const string& newName, const vector<string>& t, Hand*  h, const vector<Order*>& o)
        : name(newName), territory(t), playerHand(h), orderList(o) {}

// Copy constructor
Player::Player(const Player& p)
        : name(p.name), territory(p.territory), playerHand(p.playerHand) {
    for (Order* order : p.orderList) {
        orderList.push_back(new Order(*order));  // Assuming Order has a proper copy constructor
    }
}

// Destructor
Player::~Player() {
    for (auto order : orderList) {
        delete order;
    }
    delete playerHand;
}

// Print territories to attack
void Player::toAttack() const {
    cout << "Territories to attack: ";
    for (const auto& terr : territory) {
        cout << terr << " ";
    }
    cout << endl;
}

// Print territories to defend
void Player::toDefend() const {
    cout << "Territories to defend: ";
    for (const auto& terr : territory) {
        cout << terr << " ";
    }
    cout << endl;
}

// Issue a new order based on a string
void Player::issueOrder(const string& orderName) {
    Order* order = new Order();
    order->name = new string(orderName);
    orderList.push_back(order);

}

// Get the list of orders
vector<Order*> Player::getOrderList() const {
    return orderList;
}

// Print all orders
void Player::printOrder() const {
    cout << "Orders: ";
    for (auto order : orderList) {
        cout << *order->name << endl;  // Assuming Order has a name pointer initialized correctly.
    }
}


//---------------------------------------------------------
//             Game startup phase
//---------------------------------------------------------

//get name
string Player::getName() const {
    return name;
}
//set name
void Player::setName(const string& newName) {
    name = newName;
}

// add territory
void Player::addTerritory(const string& territoryName){
    territory.push_back(territoryName);
}

// get armies
int Player::getArmies() const{
    return armies;
}

// set armies
void Player::setArmies(const int number){
    armies = number;
}

Hand& Player::getHandCards() {
    if (playerHand) {
        return *playerHand;
    }
    throw std::runtime_error("handCards is null");
}
