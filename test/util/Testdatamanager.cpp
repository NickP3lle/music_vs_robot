#include "main.h"

#include "../../game/cash.h"
#include "../../game/playground.h"
#include "../../game/timer.h"
#include "../../music/music_instrument.h"
#include "../../robot/robot.h"
#include "../../robot/robotwtool.h"
#include "../../robot/tool.h"
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
        jsonString += "\"Cash\": " + std::to_string(Cash::get()) + ",\n";
        jsonString += "\"Timer\": " + std::to_string(Timer::getInstance()->get()) + ",\n";
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