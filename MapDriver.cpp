//-------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
//-------------------------------------------

#include "Map.h"

//A driver named testLoadMaps() that reads many different map files, creates a Map object
//for valid files and rejects the invalid ones.
void testLoadMaps() {

	// use maploader to create map objects, not sure if it has to be .txt or .map or either
	MapLoader maploader;

	maploader.LoadMap("map.txt");

	//get map from maploader getter
	//use the map object's validate()
}