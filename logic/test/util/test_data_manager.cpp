#include "main.h"

#include "../../playground/cash.h"
#include "../../playground/timer.h"
#include "../../util/data_manager_interface.h"
#include <fstream>
#include <iostream>

bool Test_data_manager_timer() {
    // std::cout << Timer::getInstance()->toString() << std::endl;
    std::ofstream outputFile("data.json");
    if (outputFile.is_open()) {
        Timer::add(1000);

        std::string jsonString = "{\n";
        jsonString += Timer::getInstance()->toString();
        jsonString += "\n}";
        outputFile << jsonString;
        outputFile.close();

        if (Timer::get() == Timer::getInstance()->fromString(jsonString)->get()) {
            return true;
        }
    }
    return false;
}

bool Test_data_manager_cash() {
    // std::cout << Cash::getInstance()->toString() << std::endl;
    std::ofstream outputFile("data.json");
    if (outputFile.is_open()) {
        Cash::add(1000);

        std::string jsonString = "{\n";
        jsonString += Cash::getInstance()->toString();
        jsonString += "\n}";
        outputFile << jsonString;
        outputFile.close();

        if (Cash::get() == Cash::getInstance()->fromString(jsonString)->get()) {
            return true;
        }
    }
    return false;
}