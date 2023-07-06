#include "timer.h"
#include <iostream>

Timer *Timer::instance = nullptr;

std::vector<TimerObserverInterface *> Timer::observers;

Timer::Timer() : time(0) {} //, stopFlag(true) {}

// void Timer::setUp() {
//   while (instance->stopFlag) {
//     instance->time++;
//     notifyObservers();
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//   }
// }

void Timer::notifyObservers() {
  for (auto observer : Timer::observers) {
    observer->updateTimer();
  }
}

void Timer::oneSecond() {
  if (instance) {
    instance->time++;
    notifyObservers();
  }
}

void Timer::start() {
  if (instance) {
    stop();
    delete instance;
  }
  instance = new Timer();
}

void Timer::stop() {
  //  if (instance) {
  //    instance->stopFlag = false;
  //    if (instance->thread->joinable())
  //      instance->thread->detach();
  //  }
}

void Timer::cleanUp() {
  if (instance) {
    stop();
    delete instance;
    instance = nullptr;
    notifyObservers();
  }
}

u32 Timer::get() { return instance->time; }

u32 Timer::minutes() { return instance->time / 60; }

u32 Timer::seconds() { return instance->time % 60; }

void Timer::registerObserver(TimerObserverInterface *obs) {
  Timer::observers.push_back(obs);
}
