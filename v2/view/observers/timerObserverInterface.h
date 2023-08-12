#ifndef TIMER_OBSERVER_INTERFACE_H
#define TIMER_OBSERVER_INTERFACE_H

class Timer;

class TimerObserverInterface {
  public:
    virtual void updateTimer() = 0;

    virtual ~TimerObserverInterface() = default;
};

#endif // TIMER_OBSERVER_INTERFACE_H