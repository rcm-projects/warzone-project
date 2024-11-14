#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "GameEngine.h"
#include "CommandProcessor.h"
#include "Map.h"
#include "Player.h"
using namespace std;

int main() {
    GameEngine engine;
    CommandProcessor commandProcessor;

    // Ask the user if they want to use console input or file input
    string inputChoice;
    cout << "Enter '-console' to use console commands or '-file <filename>' to use file commands: ";
    getline(cin, inputChoice);

    if (inputChoice.find("-console") == 0) {
        engine.Run(commandProcessor);
    }
    else if (inputChoice.find("-file") == 0) {
        string filename = inputChoice.substr(6);
        FileCommandProcessorAdapter fileCommandProcessor(filename);
        engine.Run(fileCommandProcessor);
    }
    else {
        cout << "Invalid input. Exiting." << endl;
    }

    return 0;
}