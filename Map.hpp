//-------------------------------------------
// Written by Vladimir Shterenkiker (40158317)
// Fall 2024
//-------------------------------------------

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>
#include "Player.h"

using namespace std;
using std::cout;
using std::cin;
using std::shared_ptr;

// Function declarations for string trimming
string& ltrim(string& s);
string& rtrim(string& s);
string& trim(string& s);

//Territory class
class Territory {
private:
    shared_ptr<string> name;
    shared_ptr<int> x, y;
    shared_ptr<string> continent;
    shared_ptr<string> armies;
    vector<string> neighbors;
    
public:
    // Constructor, distructor, copy constructor, assignment operator, stream insertion operator
    Territory(const string& nm, const int& posX, const int& posY, const string& cont);
    ~Territory();
    Territory(const Territory& other);
    Territory& operator=(const Territory& other);
    friend ostream& operator<<(ostream& os, const Territory& territory);
    
    
    // Getters & setters
    void addNeighbor(const string& neighbor);
    string getName() const;
    int getX() const;
    int getY() const;
    string getContinent() const;
    const vector<string>& getNeighbors() const;
    
    // friend class
    friend class GameEngine;
};

//Continent class
class Continent {
private:
    shared_ptr<string> name;
    shared_ptr<int> value;

public:
    //Constructor
    Continent(const string& nm, int val);
    
    //Distructor
    ~Continent();
    
    //Copy constructor
    Continent(const Continent& other);
    
    // Assignment operator
    Continent& operator=(const Continent& other);

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Continent& continent);

    // Getters
    string getName() const;
    int getValue() const;
};

//Map class
class Map {
private:
    shared_ptr<string> author;
    shared_ptr<string> image;
    vector<Continent> continents;
    vector<Territory> territories;

public:
    // Default constructor
    Map();
    
    //Constructor
    Map(const string& auth, const string& img);
    
    //Copy constructor
    Map(const Map& other);
    
    // Assignment operator
    Map& operator=(const Map& other);
    
    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Map& map);
    
    //Getters
    string getAuthor() const;
    string getImage() const;
    
    // Adds a collection of continents and territories to the map.
    void addTerritory(const vector<Continent>& otherContinents, const vector<Territory>& otherTerritories);
    
    // Validates the entire map.
    bool noDuplicate(const vector<Territory>& territories);
    bool isGraphConnected();
    bool isContinentConnected(const Continent& continent);
    bool validate();
    
    friend class GameEngine;
};

//MapLoader class
class MapLoader {
private:
    Map a;
public:
    // Load map, validate map
    void loadMap();
    Map loadMap(string map) const;
    void validateMap(Map& a);
};
