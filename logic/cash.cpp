#include "cash.h"

Cash *Cash::instance = nullptr;

Cash::Cash() : cash(0) {}

Cash *Cash::getInstance() {
  if (instance == nullptr) {
    instance = new Cash();
  }
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
  s += "\"Cash\": " + std::to_string(getInstance()->cash);
  return s;
}
