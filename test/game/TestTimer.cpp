#include "main.h"

bool TestTimer() {
  Timer::start();
  int i = 1;
  std::this_thread::sleep_for(std::chrono::seconds(i));
  Timer::stop();
  if (Timer::get() < i) {
    return false;
  }
  Timer::start();
  std::this_thread::sleep_for(std::chrono::seconds(i));
  Timer::get();
  std::this_thread::sleep_for(std::chrono::seconds(i));
  Timer::cleanUp();
  std::this_thread::sleep_for(std::chrono::seconds(i));
  Timer::stop();
  std::this_thread::sleep_for(std::chrono::seconds(i));
  Timer::start();
  std::this_thread::sleep_for(std::chrono::seconds(i));
  Timer::stop();
  return true;
}
