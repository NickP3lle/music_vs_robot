#pragma once

#include "../util/dataManager.h"
#include "../view/observers/timerObserverInterface.h"
#include <atomic>
#include <chrono>
#include <thread>
#include <vector>

#define u32 unsigned int

class Timer : public DataManagerInterface {
  private:
    static Timer *instance;
    u32 time;
    Timer();

    static std::vector<TimerObserverInterface *> observers;
    static void notifyObservers();

  public:
    static Timer *getInstance();
    static void oneSecond();
    static void start();
    static void cleanUp();
    static u32 get();
    static u32 minutes();
    static u32 seconds();

    static void registerObserver(TimerObserverInterface *obs);

    virtual std::string saveData() const override;
    virtual Timer *loadData(std::string) override;
};
