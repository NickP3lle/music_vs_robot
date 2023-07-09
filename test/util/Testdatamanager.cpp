#include "main.h"

#include "../../game/cash.h"
#include "../../game/playground.h"
#include "../../game/timer.h"
#include "../../music/music_instrument.h"
#include "../../robot/robot.h"
#include "../../robot/robotwtool.h"
#include "../../robot/tool.h"
#include "../../util/dataManager.h"
#include <fstream>
#include <iostream>

bool TestDataManageSaveData() {
    std::ofstream outputFile("data.json");
    if (outputFile.is_open()) {
        Cash::add(10000);
        MusicInstruments *flute = new Flute();
        MusicInstruments *drum = new Drum();
        MusicInstruments *saxophone = new Saxophone();
        MusicInstruments *trumpet = new Trumpet();
        MusicInstruments *violin = new Violin();
        Playground::getInstance()->playerInsert(3, 7, flute);
        Playground::getInstance()->playerInsert(1, 8, drum);
        Playground::getInstance()->playerInsert(4, 9, saxophone);
        Playground::getInstance()->playerInsert(0, 2, trumpet);
        Playground::getInstance()->playerInsert(2, 5, violin);
        // RobotWTool *robotWTool = new RobotWTool(1, 1);
        std::string jsonString = "{\n";
        jsonString += Cash::getInstance().saveData() + ",\n";
        jsonString += Timer::getInstance()->saveData() + ",\n";
        // jsonString += flute->saveData();
        // jsonString += ",\n" + drum->saveData();
        // jsonString += ",\n" + saxophone->saveData();
        // jsonString += ",\n" + trumpet->saveData();
        // jsonString += ",\n" + violin->saveData();
        // jsonString += ",\n" + robotWTool->saveData();
        jsonString += Playground::getInstance()->saveData();
        jsonString += "\n}";
        outputFile << jsonString;
        outputFile.close();
        return true;
    } else {
        return false;
    }
}

bool TestDataManagerLoadData() {
    std::ifstream inputFile("data.json");
    if (inputFile.is_open()) {
        std::string tmp;
        std::string line;
        bool playgroundFound = false;
        while (std::getline(inputFile, line)) {
            if (line == "{" && !playgroundFound) {
                continue;
            }
            if (playgroundFound && line == "]") {
                // std::cout << tmp << std::endl;
                if (Playground::getInstance()->loadData(tmp)) {
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
                    if (Cash::getInstancePtr()->loadData(line)) {
                        std::cout << "Cash loaded successfully." << std::endl;
                    } else {
                        std::cerr << "Failed to load cash." << std::endl;
                        return false;
                    }
                } else if (token == "\"Timer\"") {
                    if (Timer::getInstance()->loadData(line)) {
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