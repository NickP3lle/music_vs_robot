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

void Timer::oneSecond() { Timer::add(1); }

u32 Timer::get() { return getInstance()->t; }

// tutti i campi dati di Timer sono cancellati, quindi anche gli osservatori
// sono cancellati
void Timer::cleanUp() {
  if (instance == nullptr)
    return;
  delete instance;
  instance = nullptr;
}

void Timer::start() { getInstance()->t = 0; }

u32 Timer::minutes() { return getInstance()->t / 60; }

u32 Timer::seconds() { return getInstance()->t % 60; }

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
