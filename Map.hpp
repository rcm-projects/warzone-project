#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class Territory
class Territory {
private:
    string* name;
    int* x;
    int* y;
    string* continent;
    int* armies;
    vector<Territory*>* adjacent;
    string* player;
      
    
public:
    // Constructor, copy constructor, distructor, Assignment operator
    Territory(string name, int x, int y, string continent);
    Territory(const Territory& other);
    Territory& operator=(const Territory& other);
    ~Territory();
    
    //getters
    string getName() const;
    int getX() const;
    int getY() const;
    string getContinent() const;
    int getArmies() const;
    vector<Territory*> getAdjacent() const;
    string getPlayer() const;
    
    
    //setters
    void setArmies(int numArmies);
    void addAdjacent(Territory* territory);
    void setPlayer(string player);
    
    // Stream insertion operator (friend function)
    friend ostream& operator<<(ostream& os, const Territory& t);
};

#endif
