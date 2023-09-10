#include "data_manager.h"

#include "../playground/cash.h"
#include "../playground/game.h"
#include "../playground/timer.h"

void DataManagerInterface::saveAll() {
    std::ofstream outputFile("./data.json");
    if (outputFile.is_open()) {
        std::string jsonString = "{\n";
        jsonString += Cash::getInstance()->toString() + ",\n";
        jsonString += Timer::getInstance()->toString() + ",\n";
        jsonString += Game::getInstance()->toString();
        jsonString += "\n}";
        outputFile << jsonString;
        outputFile.close();
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }
}

bool DataManagerInterface::loadAll() {
    std::ifstream inputFile("./data.json");
    if (inputFile.is_open()) {
        std::string tmp;
        std::string line;
        bool playgroundFound = false;
        while (std::getline(inputFile, line)) {
            if (line == "{" && !playgroundFound) {
                continue;
            }
            if (playgroundFound && line == "]") {
                if (Game::getInstance()->fromString(tmp)) {
                    std::cout << "Playground loaded successfully." << std::endl;
                } else {
                    std::cerr << "Failed to load playground." << std::endl;
                    return false;
                }
                break;
            }
            tmp += line;

            if (playgroundFound) {
                continue;
            }

            size_t pos = line.find(':');
            if (pos != std::string::npos) {
                std::string token = line.substr(0, pos);
                if (token == "\"Cash\"") {
                    if (Cash::getInstance()->fromString(line)) {
                        std::cout << "Cash loaded successfully." << std::endl;
                    } else {
                        std::cerr << "Failed to load cash." << std::endl;
                        return false;
                    }
                } else if (token == "\"Timer\"") {
                    if (Timer::getInstance()->fromString(line)) {
                        std::cout << "Timer loaded successfully." << std::endl;
                    } else {
                        std::cerr << "Failed to load timer." << std::endl;
                        return false;
                    }
                } else if (token == "\"Playground\"") {
                    playgroundFound = true;
                    tmp = "";
                }
            }
        }
        inputFile.close();
        return true;
    } else {
        return false;
    }
}
