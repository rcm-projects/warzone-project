//-------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
//-------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Map.h"
using namespace std;

// Note: - Must contain class for Map objects (graph data structure), Map loader class (reads text files that hold map data, creates map object), and territory class (nodes of graph), maybe continent class idk.
//		 - The parsing is okay, but im not sure if the map and territories are stored correctly. It has to be a graph data structure, Im just not sure how to implement that. Also something about continents being a subgraph. 
//		 - The data types are not pointer types, they need to be converted.

//---------------------------------------------------------
//		Map
//---------------------------------------------------------

Map::Map() {

}

void Map::validate() {
	/*
	From assignment description:

	The Map class includes a validate() method that makes the following checks: 1) the map is
	a connected graph, 2) continents are connected subgraphs and 3) each country belongs to
	one and only one continent.

	*/
}

//---------------------------------------------------------
//		Territory
//---------------------------------------------------------

// constructor for MapLoader to use
Territory::Territory(string TName, int XCoord, int YCoord, string Continent, vector<string> Adjacents) {
	name = TName;
	xCoord = XCoord;
	yCoord = YCoord;
	continent = Continent;
	adjacents = Adjacents;
	PlayerOwner = "None";
	NumArmies = 0;
}

//---------------------------------------------------------
//		MapLoader
//---------------------------------------------------------

// Takes a textfile, parses the info and puts it into a Map object.
Map MapLoader::LoadMap(string textfile) {
	Map LoadedMap;
	ifstream file(textfile);
	string RawData;

	// whitespace isnt being handled, not sure if it will need to be
	if (file.is_open()) {

//------------------
// Reading Map Info	
//------------------

		// what were trying to get from the unparsed data
		string image;
		string wrap;
		string scroll;
		string author;
		string warn;
	
		// Skip the first line
		getline(file, RawData);

		getline(file, RawData);
		size_t pos = RawData.find('=');
		if (pos != string::npos) {
			image = RawData.substr(pos + 1);
		}

		getline(file, RawData);
		size_t pos = RawData.find('=');
		if (pos != string::npos) {
			wrap = RawData.substr(pos + 1);
		}

		getline(file, RawData);
		size_t pos = RawData.find('=');
		if (pos != string::npos) {
			scroll = RawData.substr(pos + 1);
		}

		getline(file, RawData);
		size_t pos = RawData.find('=');
		if (pos != string::npos) {
			author = RawData.substr(pos + 1);
		}

		getline(file, RawData);
		size_t pos = RawData.find('=');
		if (pos != string::npos) {
			warn = RawData.substr(pos + 1);
		}
			
//------------------------
// Reading Continent Info
//------------------------

		// what were trying to get from the unparsed data
		map<string, int> continents;

		// Skip the first line
		getline(file, RawData);

		while (getline(file, RawData)) {
			//parse

			size_t pos = RawData.find('=');
			if (pos != string::npos) {

				string key = RawData.substr(0, pos);
				int value = stoi(RawData.substr(pos + 1));

				continents[key] = value; // Store them in the map
			}


		}

//------------------------
// Reading Territory Info
//------------------------

		// what were trying to get from the unparsed data
		vector<Territory> territories;
		string TNameTemp;
		int XCoordTemp;
		int YCoordTemp;
		string ContinentTemp;
		string temp;

		// Skip the first line
		getline(file, RawData);

		// Loops over each line and creates a territory object for it, then stores in an vector
		while (getline(file, RawData)) {
			// vector needs to be reset so it goes in the loop
			vector<string> AdjacentsTemp;

			stringstream ss(RawData);

			getline(ss, TNameTemp, ',');
			ss >> XCoordTemp; ss.ignore();
			ss >> YCoordTemp; ss.ignore();
			getline(ss, ContinentTemp, ',');

			while (getline(ss, temp, ',')) {
				AdjacentsTemp.push_back(temp);
			}

			//create territory obj and add to array
			territories.push_back(Territory(TNameTemp, XCoordTemp, YCoordTemp, ContinentTemp, AdjacentsTemp));
		}
		file.close();
	}



	else {
		cout << "Unable to open file." << endl;
	}
	

	return LoadedMap;

}

