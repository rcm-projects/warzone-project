#include "CommandProcessor.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void CommandProcessor::readCommand() {
    cout << "Enter command: ";
    getline(cin, currentCommand);
}

void CommandProcessor::saveCommand() {
    commands.push_back(currentCommand);
}

string CommandProcessor::getCommand() {
    readCommand();
    saveCommand();
    return currentCommand;
}

FileCommandProcessorAdapter::FileCommandProcessorAdapter(const string& filename) {
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            commands.push_back(line);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

string FileCommandProcessorAdapter::getCommand() {
    if (!commands.empty()) {
        string command = commands.front();
        commands.erase(commands.begin());
        return command;
    }
    return "";
}
