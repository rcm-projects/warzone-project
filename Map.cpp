//-------------------------------------------
// Written by Vladimir Shterenkiker (40158317)
// Fall 2024
//-------------------------------------------

#include "Map.hpp"


//---------------------------------------------------------
//        Trimming functions
//---------------------------------------------------------

// Removes leading whitespace.
string& ltrim(string& s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    return s;
}

// Removes trailing whitespace.
string& rtrim(string& s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
    return s;
}

// Removes both leading and trailing whitespace.
string& trim(string& s) {
    return ltrim(rtrim(s));
}


//---------------------------------------------------------
//        Territory methods
//---------------------------------------------------------

// Constructor.
Territory::Territory(const string& nm, const int& posX, const int& posY, const string& cont)
    : name(make_shared<string>(nm)),
    x(make_shared<int>(posX)),
    y(make_shared<int>(posX)),
    continent(make_shared<string>(cont)) {}

//Distructor
Territory::~Territory(){
}

// Copy Constructor
Territory::Territory(const Territory& other)
    : name(make_shared<string>(*other.name)),
    x(make_shared<int>(*other.x)),
    y(make_shared<int>(*other.y)),
    continent(make_shared<string>(*other.continent)),
    neighbors(other.neighbors) {}

// Assignment operator
Territory& Territory::operator=(const Territory& other) {
        if (this != &other) {
            name = make_shared<string>(*other.name);
            x = make_shared<int>(*other.x);
            y = make_shared<int>(*other.y);
            continent = make_shared<string>(*other.continent);
            neighbors = other.neighbors;
        }
        return *this;
}

// Stream insertion operator
ostream& operator<<(ostream& os, const Territory& territory) {
    os << "Territory: " << *territory.name
       << " (" << *territory.x << ", " << *territory.y << "), "
       << "Continent: " << *territory.continent << ", "
       << "Neighbors: ";
    for (const auto& neighbor : territory.neighbors) {
        os << neighbor << " ";
    }
    return os;
}
// Adds a neighbor.
void Territory::addNeighbor(const string& neighbor) {
    neighbors.push_back(neighbor);
}

// Returns the name.
string Territory::getName() const { return *name; }

// Returns the x-coordinate.
int Territory::getX() const { return *x; }

// Returns the y-coordinate.
int Territory::getY() const { return *y; }

// Returns the continent.
string Territory::getContinent() const { return *continent; }

// Returns neighbors.
const vector<string>& Territory::getNeighbors() const { return neighbors; }

//---------------------------------------------------------
//        Continent methods
//---------------------------------------------------------

// Constructor.
Continent::Continent(const string& nm, int val) : name(make_shared<string>(nm)), value(make_shared<int>(val)) {}

//Distructor
Continent::~Continent(){}

//Copy constructor
Continent::Continent(const Continent& other): name(make_shared<string>(*other.name)), value(make_shared<int>(*other.value)) {}

// Returns the name.
string Continent::getName() const { return *name; }

// Returns the value.
int Continent::getValue() const { return *value; }

// Assignment operator
Continent& Continent::operator=(const Continent& other) {
    if (this != &other) {
        name = make_shared<string>(*other.name);
        value = make_shared<int>(*other.value);
    }
    return *this;
}

// Stream insertion operator
ostream& operator<<(ostream& os, const Continent& continent) {
    os << "Continent: " << *continent.name
       << ", Control Value: " << *continent.value;
    return os;
}

//---------------------------------------------------------
//       Map methods
//---------------------------------------------------------

// Default constructor
Map::Map() : author(nullptr), image(nullptr) {}

// Constructor.
Map::Map(const string& auth, const string& img) : author(make_shared<string>(auth)), image(make_shared<string>(img)) {}

//Copy constructor
Map::Map(const Map& other):
    author(make_shared<string>(*other.author)),
    image(make_shared<string>(*other.image)),
    continents(other.continents),
    territories(other.territories) {}

// Assignment operator for Map
Map& Map::operator=(const Map& other) {
    if (this != &other) {
        author = make_shared<string>(*other.author);
        image = make_shared<string>(*other.image);
        continents = other.continents;
        territories = other.territories;
    }
    return *this;
}

// Stream insertion operator for Map
ostream& operator<<(ostream& os, const Map& map) {
    os << "Map Author: " << *map.author << "\n"
       << "Image: " << *map.image << "\n"
       << "Continents: \n";
    for (const auto& continent : map.continents) {
        os << continent << "\n";
    }
    os << "Territories: \n";
    for (const auto& territory : map.territories) {
        os << territory << "\n";
    }
    return os;
}

// Returns the author.
string Map::getAuthor() const { return *author; }

// Returns the image.
string Map::getImage() const { return *image; }

// Adds continents and territories.
void Map::addTerritory(const vector<Continent>& otherContinents, const vector<Territory>& otherTerritories) {
    continents = otherContinents;
    territories = otherTerritories;
    cout << "Adding territories and continents" << endl;
}

// Check if there is duplicate territories
bool noDuplicate(const vector<Territory>& territories) {
    set<string> names;
    for (const auto& territory : territories) {
        names.insert(territory.getName());
    }
    return names.size() == territories.size();
}


// Checks if the map is fully connected.
bool Map::isGraphConnected() {
    if (territories.empty()) return true;

    unordered_set<string> visited;
    queue<string> toVisit;

    toVisit.push(territories.front().getName());
    while (!toVisit.empty()) {
        string current = toVisit.front();
        toVisit.pop();

        if (visited.count(current)) continue;
        visited.insert(current);

        auto it = find_if(territories.begin(), territories.end(), [&](const Territory& t) {
            return t.getName() == current;
        });
        if (it != territories.end()) {
            for (const string& neighbor : it->getNeighbors()) {
                if (!visited.count(neighbor)) {
                    toVisit.push(neighbor);
                }
            }
        }
    }
    return visited.size() == territories.size();
}

// Checks if a continent is connected.
bool Map::isContinentConnected(const Continent& continent) {
    vector<Territory> continentTerritories;
    for (const auto& territory : territories) {
        if (territory.getContinent() == continent.getName()) {
            continentTerritories.push_back(territory);
        }
    }

    if (continentTerritories.empty()) return true;

    unordered_set<string> visited;
    queue<string> toVisit;

    toVisit.push(continentTerritories.front().getName());
    while (!toVisit.empty()) {
        string current = toVisit.front();
        toVisit.pop();

        if (visited.count(current)) continue;
        visited.insert(current);

        auto it = find_if(continentTerritories.begin(), continentTerritories.end(), [&](const Territory& t) {
            return t.getName() == current;
        });
        if (it != continentTerritories.end()) {
            for (const string& neighbor : it->getNeighbors()) {
                if (find_if(continentTerritories.begin(), continentTerritories.end(), [&](const Territory& t) {
                    return t.getName() == neighbor;
                }) != continentTerritories.end()) {
                    if (!visited.count(neighbor)) {
                        toVisit.push(neighbor);
                    }
                }
            }
        }
    }
    return visited.size() == continentTerritories.size();
}

// Validates the map.
bool Map::validate() {
    if (continents.empty() || territories.empty()) {
        cout << "Validation failed: No continents or territories to validate." << endl;
        return false;
    }

    if (!isGraphConnected()) {
        cout << "The map is not a connected graph." << endl;
        return false;
    }

    for (const auto& continent : continents) {
        if (!isContinentConnected(continent)) {
            cout << "Continent " << continent.getName() << " is not a connected subgraph." << endl;
            return false;
        }
    }
    return true;
}


//---------------------------------------------------------
//       MapLoader methods
//---------------------------------------------------------

// Loads map data from a file.
void MapLoader::loadMap(){
    ifstream file("/GameMaps/Africa.map");
    string line;

    vector<Map> map;
    vector<Continent> continents;
    vector<Territory> territories;

    enum Section { NONE, MAP, CONTINENTS, TERRITORIES } currentSection = NONE;

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return;
    }

    while (getline(file, line)) {
        line = trim(line);
        if (line.empty()) continue;

        if (line == "[Map]") {
            currentSection = MAP;
            continue;
        } else if (line == "[Continents]") {
            currentSection = CONTINENTS;
            continue;
        } else if (line == "[Territories]") {
            currentSection = TERRITORIES;
            continue;
        }

        switch (currentSection) {
            case NONE:{
                break;
            }
            case MAP: {
                size_t pos = line.find('=');
                if (pos != string::npos) {
                    map.emplace_back(line.substr(0, pos), line.substr(pos + 1));
                }
                break;
            }
            case CONTINENTS: {
                size_t pos = line.find('=');
                if (pos != string::npos) {
                    continents.emplace_back(line.substr(0, pos), stoi(line.substr(pos + 1)));
                }
                break;
            }
            case TERRITORIES: {
                istringstream ss(line);
                string name, coord_x, coord_y, continent;
                getline(ss, name, ',');
                getline(ss, coord_x, ',');
                getline(ss, coord_y, ',');
                getline(ss, continent, ',');
                Territory territory(name, stoi(coord_x), stoi(coord_y), continent);

                string neighbor;
                while (getline(ss, neighbor, ',')) {
                    territory.addNeighbor(trim(neighbor));
                }

                territories.push_back(territory);
                break;
            }
        }
    }

    file.close();

    // Output information
    for (const auto& territory : territories) {
        cout << "Territory Name: " << territory.getName() << endl;
        cout << "Coordinates: (" << territory.getX() << ", " << territory.getY() << ")" << endl;
        cout << "Continent: " << territory.getContinent() << endl;
        cout << "Neighbors: ";
        for (const auto& neighbor : territory.getNeighbors()) {
            cout << neighbor << ", ";
        }
        cout << endl << endl;
    }

    for (const auto& continent : continents) {
        cout << "Continent Name: " << continent.getName() << ", Control Value: " << continent.getValue() << endl;
    }

    for (const auto& info : map) {
        cout << "Author: " << info.getAuthor() << ", Image: " << info.getImage() << endl;
    }

    // Output verification
    cout << "Map Info: " << map.size() << " entries." << endl;
    cout << "Continents: " << continents.size() << " entries." << endl;
    cout << "Territories: " << territories.size() << " entries." << endl;

    // Save territories and continents
    map[0].addTerritory(continents, territories);
  
}




//---------------------------------------------------------
//             Game startup phase
//---------------------------------------------------------
// loadMap and return Map object
Map MapLoader::loadMap(string map) const {
    
    string select_map = map;
    ifstream file;
    if(select_map == "USA"){
        file.open("/GameMaps/USA.map");
    } else if (select_map == "Africa"){
        file.open("/Africa.map");
    } else if (select_map == "Alberta"){
        file.open("/Alberta.map");
    }
    
    string line;
    vector<Map> map1;
    vector<Continent> continents;
    vector<Territory> territories;

    enum Section { NONE, MAP, CONTINENTS, TERRITORIES } currentSection = NONE;

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        //return;
    }

    while (getline(file, line)) {
        line = trim(line);
        if (line.empty()) continue;

        if (line == "[Map]") {
            currentSection = MAP;
            continue;
        } else if (line == "[Continents]") {
            currentSection = CONTINENTS;
            continue;
        } else if (line == "[Territories]") {
            currentSection = TERRITORIES;
            continue;
        }

        switch (currentSection) {
            case NONE:{
                break;
            }
            case MAP: {
                size_t pos = line.find('=');
                if (pos != string::npos) {
                    map1.emplace_back(line.substr(0, pos), line.substr(pos + 1));
                }
                break;
            }
            case CONTINENTS: {
                size_t pos = line.find('=');
                if (pos != string::npos) {
                    continents.emplace_back(line.substr(0, pos), stoi(line.substr(pos + 1)));
                }
                break;
            }
            case TERRITORIES: {
                istringstream ss(line);
                string name, coord_x, coord_y, continent;
                getline(ss, name, ',');
                getline(ss, coord_x, ',');
                getline(ss, coord_y, ',');
                getline(ss, continent, ',');
                Territory territory(name, stoi(coord_x), stoi(coord_y), continent);

                string neighbor;
                while (getline(ss, neighbor, ',')) {
                    territory.addNeighbor(trim(neighbor));
                }

                territories.push_back(territory);
                break;
            }
        }
    }

    file.close();

    // Output information
    for (const auto& territory : territories) {
        cout << "Territory Name: " << territory.getName() << endl;
        cout << "Coordinates: (" << territory.getX() << ", " << territory.getY() << ")" << endl;
        cout << "Continent: " << territory.getContinent() << endl;
        cout << "Neighbors: ";
        for (const auto& neighbor : territory.getNeighbors()) {
            cout << neighbor << ", ";
        }
        cout << endl << endl;
    }

    for (const auto& continent : continents) {
        cout << "Continent Name: " << continent.getName() << ", Control Value: " << continent.getValue() << endl;
    }

    for (const auto& info : map1) {
        cout << "Author: " << info.getAuthor() << ", Image: " << info.getImage() << endl;
    }

    // Output verification
    cout << "Map Info: " << map.size() << " entries." << endl;
    cout << "Continents: " << continents.size() << " entries." << endl;
    cout << "Territories: " << territories.size() << " entries." << endl;

    // Save territories and continents
    map1[0].addTerritory(continents, territories);
    
    Map a = map1[0];
    return a;
}
