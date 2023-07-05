#pragma once

class Timer;

class TimerObserverInterface {
public:
  virtual void updateTimer() = 0;

  virtual ~TimerObserverInterface() = default;
};
