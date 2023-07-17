#include "timer.h"

Timer *Timer::instance = nullptr;

Timer::Timer() : t(0) {}

Timer *Timer::getInstance() {
  if (instance == nullptr)
    instance = new Timer();
  return instance;
}

void Timer::add(u32 amount) {
  getInstance()->t += amount;
  instance->notify();
}

bool Timer::sub(u32 amount) {
  if (amount > getInstance()->t)
    return false;
  instance->t -= amount;
  instance->notify();
  return true;
}

u32 Timer::get() { return getInstance()->t; }

void Timer::cleanUp() {
  if (instance == nullptr)
    return;
  delete instance;
  instance = nullptr;
}

std::string Timer::toString() const {
  std::string s;
  s += "\"Timer\": " + std::to_string(getInstance()->t);
  return s;
}
