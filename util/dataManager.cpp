#include "dataManager.h"

#include "../game/cash.h"
#include "../game/playground.h"
#include "../game/timer.h"

void DataManagerInterface::saveAll() {
    std::ofstream outputFile("data.json");
    if (outputFile.is_open()) {
        std::string jsonString = "{\n";
        jsonString += Cash::getInstance().saveData() + ",\n";
        jsonString += Timer::getInstance()->saveData() + ",\n";
        jsonString += Playground::getInstance()->saveData();
        jsonString += "\n}";
        outputFile << jsonString;
        outputFile.close();
    }
}