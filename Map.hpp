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

using namespace std;

// Function declarations for string trimming
string& ltrim(string& s);
string& rtrim(string& s);
string& trim(string& s);

//Territory class
class Territory {
private:
    string name;
    int x, y;
    string continent;
    vector<string> neighbors;

public:
    // Constructor
    Territory(const string& nm, int posX, int posY, const string& cont);
    
    // Assignment operator
    Territory& operator=(const Territory& other);

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Territory& territory);
    
    // Add Neighbors to the territory
    void addNeighbor(const string& neighbor);
    
    // Getters
    string getName() const;
    int getX() const;
    int getY() const;
    string getContinent() const;
    const vector<string>& getNeighbors() const;
};

//Continent class
class Continent {
private:
    string name;
    int value;

public:
    //Constructor
    Continent(const string& nm, int ctrlVal);
    
    // Assignment operator
    Continent& operator=(const Continent& other);

    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Continent& continent);

    
    // Setters
    void setName(const string& nm);
    void setControlValue(int ctrlVal);
     
    // Getters
    string getName() const;
    int getControlValue() const;
};

//Map class
class Map {
private:
    string author;
    string image;
    vector<Continent> continents;
    vector<Territory> territories;

public:
    //Constructor
    Map(const string& auth, const string& img);
    
    // Assignment operator
    Map& operator=(const Map& other);
    
    // Stream insertion operator
    friend ostream& operator<<(ostream& os, const Map& map);
    
    //Setters
    void setAuthor(const string& auth);
    void setImage(const string& img);
    
    //Getters
    string getAuthor() const;
    string getImage() const;
    
    // Adds a collection of continents and territories to the map.
    void addTerritory(const vector<Continent>& otherContinents, const vector<Territory>& otherTerritories);
    
    // Validates the entire map, checking for connectivity and integrity.
    bool isGraphConnected();
    bool isContinentConnected(const Continent& continent);
    bool validate();
};

//MapLoader class
class MapLoader {
public:
    // Loads the map data from a file.
    void loadMap();
};
