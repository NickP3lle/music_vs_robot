#pragma once

#include "../view/observers/timerObserverInterface.h"
#include <atomic>
#include <chrono>
#include <thread>
#include <vector>

#define u32 unsigned int

class Timer {
private:
  static Timer *instance;
  std::atomic<u32> time;
  std::atomic<bool> stopFlag;
  std::thread *thread;
  Timer();
  static void setUp();

  static std::vector<TimerObserverInterface *> observers;
  static void notifyObservers();

public:
  static void start();
  static void stop();
  static void reset();
  static u32 get();
  static u32 minutes();
  static u32 seconds();
};
