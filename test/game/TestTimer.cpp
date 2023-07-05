#include "main.h"

bool TestTimer() {
  Timer::start();
  int i = 1;
  std::this_thread::sleep_for(std::chrono::seconds(i));
  Timer::stop();
  if (Timer::get() < i) {
    return false;
  }
  return true;
}
