#include "cash.h"

Cash *Cash::instance = nullptr;

std::vector<CashObserverInterface *> Cash::observers;

Cash &Cash::getInstance() {
    if (instance == nullptr) {
        instance = new Cash();
    }
    return *instance;
}

Cash *Cash::getInstancePtr() {
    if (instance == nullptr) {
        instance = new Cash();
    }
    return instance;
}

Cash::Cash() : total(0) {}

void Cash::cleanUp() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
    notifyObservers();
}

void Cash::add(u32 amount) {
    getInstance().total += amount;
    notifyObservers();
}

bool Cash::sub(u32 amount) {
    if (getInstance().total < amount) {
        // std::cerr << "Not enough cash\n";
        return false;
    }
    getInstance().total -= amount;
    notifyObservers();
    return true;
}

u32 Cash::get() { return getInstance().total; }

void Cash::notifyObservers() {
    for (auto obs : observers) {
        obs->updateCash();
    }
}

void Cash::registerObserver(CashObserverInterface *obs) { observers.push_back(obs); }

std::string Cash::saveData() {
    std::string tmp;
    tmp += "\"Cash\": " + std::to_string(total);
    return tmp;
}

Cash *Cash::loadData(std::string data) {
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
    total = std::stoi(data.substr(start, len));
    notifyObservers();
    return this;
}