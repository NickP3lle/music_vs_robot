#include "cash.h"

Cash *Cash::instance = nullptr;

Cash::Cash() : cash(0) {}

Cash *Cash::getInstance() {
    if (instance == nullptr)
        instance = new Cash();
    return instance;
}

void Cash::add(u32 amount) {
    getInstance()->cash += amount;
    instance->notify();
}

bool Cash::sub(u32 amount) {
    if (amount > getInstance()->cash)
        return false;
    instance->cash -= amount;
    instance->notify();
    return true;
}

u32 Cash::get() { return getInstance()->cash; }

void Cash::cleanUp() {
    if (instance == nullptr)
        return;
    delete instance;
    instance = nullptr;
}

std::string Cash::toString() const {
    std::string s;
    s += "\"Cash\": " + std::to_string(cash);
    return s;
}

Cash *Cash::fromString(std::string data) {
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
    cash = std::stoi(data.substr(start, len));
    notify();
    return this;
}
