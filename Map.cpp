#include "Map.hpp"

//Constructor
Territory::Territory(string name, int x, int y, string continent) {
    this->name = new string(name);
    this->x = new int(x);
    this->y = new int(y);
    this->continent = new string(continent);
    this->armies = new int(0);
    this->adjacent = new vector<Territory*>();
    this->player = new string("None");
}
// Copy constructor
Territory::Territory(const Territory& other) {
    name = new string(*other.name);
    x = new int(*other.x);
    y = new int(*other.y);
    continent = new string(*other.continent);
    armies = new int(*other.armies);
    adjacent = new vector<Territory*>(*other.adjacent);
    player = new string(*other.player);
}
// Assignment Operator
Territory& Territory::operator=(const Territory& other) {
    if (this != &other) {
        // Clean up existing resources
        delete name;
        delete x;
        delete y;
        delete continent;
        delete armies;
        delete adjacent;
        delete player;

        // Allocate new resources and copy values from the other object
        name = new string(*other.name);
        x = new int(*other.x);
        y = new int(*other.y);
        continent = new string(*other.continent);
        armies = new int(*other.armies);
        adjacent = new vector<Territory*>(*other.adjacent);
        player = new string(*other.player);
    }
    return *this;
}
// Destructor
Territory::~Territory() {
    delete name;
    delete x;
    delete y;
    delete continent;
    delete armies;
    delete adjacent;  
    delete player;
}



// Getters
string Territory::getName() const {
    return *name;
}
int Territory::getX() const {
    return *x;
}
int Territory::getY() const {
    return *y;
}
string Territory::getContinent() const {
    return *continent;
}
int Territory::getArmies() const {
    return *armies;
}
string Territory::getPlayer() const {
    return *player;
}
vector<Territory*> Territory::getAdjacent() const {
    return *adjacent;
}



// Setters
void Territory::setArmies(int numArmies) {
    *armies = numArmies;
}
void Territory::addAdjacent(Territory* territory) {
    adjacent->push_back(territory);
}
void Territory::setPlayer(string player) {
    *this->player = player;
}



// Stream insertion operator
ostream& operator<<(ostream& os, const Territory& t) {
    os << "Territory: " << *t.name << "\n"
       << "Coordinates: (" << *t.x << ", " << *t.y << ")\n"
       << "Continent: " << *t.continent << "\n"
       << "Armies: " << *t.armies << "\n"
       <<"Player: " << *t.player << "\n"
       << "Adjacent Territories: ";

    // Dereference the pointer to the adjacent vector
    for (const auto& adj : *(t.adjacent)) {
        os << adj->getName() << " ";
    }

    os << endl;
    return os;
}
