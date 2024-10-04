//-------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
//-------------------------------------------

#pragma once

#include <string>
#include <vector>
#include <map>
using namespace std;

class Map
{
public:
	Map();
	void validate();
private:
	string image;
	string wrap;
	string scroll;
	string author;
	string warn;

	//string MapName; ?
	vector<Territory> territories;
	map<string, int> continents;
};

class Territory
{
public:
	Territory(string TName, int XCoord, int YCoord, string Continent, vector<string> Adjacents);

private:
	string name;
	int xCoord;
	int yCoord;
	string continent;
	vector<string> adjacents;

	string PlayerOwner;
	int NumArmies;
};

class MapLoader
{
public:
	Map LoadMap(string textfile);

	//getter for map
private:
	
};
