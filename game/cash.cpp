#include "cash.h"

Cash *Cash::instance = nullptr;

Cash *Cash::getInstance() {
    if (instance == nullptr) {
        instance = new Cash();
    }
    return instance;
}

Cash::Cash() { total = 1000; }

void Cash::add(u32 amount) {
    total += amount;
    notifyObservers();
}

bool Cash::sub(u32 amount) {
    if (total < amount) {
        // std::cerr << "Not enough cash\n";
        return false;
    }
    total -= amount;
    notifyObservers();
    return true;
}

u32 Cash::getTotal() { return total; }

void Cash::notifyObservers() {
    for (auto obs : observers) {
        obs->updateCash();
    }
}

void Cash::registerObserver(CashObserverInterface *obs) { observers.push_back(obs); }