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

void Timer::oneSecond() { Timer::add(1); }

u32 Timer::get() { return getInstance()->t; }

void Timer::cleanUp() {
  if (instance == nullptr)
    return;
  delete instance;
  instance = nullptr;
}

std::string Timer::toString() const {
  std::string s;
  s += "\"Timer\": " + std::to_string(t);
  return s;
}

Timer *Timer::fromString(std::string data) {
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
  t = std::stoi(data.substr(start, len));
  notify();
  return this;
}
