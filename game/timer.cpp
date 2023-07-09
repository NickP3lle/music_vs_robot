#include "timer.h"
#include <iostream>

Timer *Timer::instance = nullptr;

std::vector<TimerObserverInterface *> Timer::observers;

Timer::Timer() : time(0) {}

void Timer::notifyObservers() {
    for (auto observer : Timer::observers) {
        observer->updateTimer();
    }
}

Timer *Timer::getInstance() {
    if (!instance) {
        instance = new Timer();
    }
    return instance;
}

void Timer::start() { getInstance(); }

void Timer::oneSecond() {
    getInstance()->time++;
    notifyObservers();
}

void Timer::cleanUp() {
    if (instance) {
        delete instance;
        instance = nullptr;
    }
}

u32 Timer::get() { return instance->time; }

u32 Timer::minutes() { return instance->time / 60; }

u32 Timer::seconds() { return instance->time % 60; }

void Timer::registerObserver(TimerObserverInterface *obs) { Timer::observers.push_back(obs); }

std::string Timer::saveData() {
    std::string tmp;
    tmp += "\"Timer\": " + std::to_string(time);
    return tmp;
}

Timer *Timer::loadData(std::string data) {
    size_t start = data.find(": ") + 2;
    if (start == std::string::npos) {
        return nullptr;
    }
    size_t commaPos = data.find(",");
    if (commaPos == std::string::npos) {
        commaPos = 20;
    }
    int len = commaPos - start;
    if (len < 0) {
        return nullptr;
    }
    time = std::stoi(data.substr(start, len));
    notifyObservers();
    return this;
}