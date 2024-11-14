#pragma once


#include <string>
#include <vector>

class CommandProcessor {
public:
    void readCommand();
    void saveCommand();
    std::string getCommand();

private:
    std::string currentCommand;
    std::vector<std::string> commands;
};

class FileCommandProcessorAdapter : public CommandProcessor {
public:
    FileCommandProcessorAdapter(const std::string& filename);
    std::string getCommand();

private:
    std::vector<std::string> commands;
};
