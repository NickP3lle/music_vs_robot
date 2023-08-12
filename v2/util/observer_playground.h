#pragma once
#define u32 unsigned int

template <typename T> class PlaygroundObserverInterface {
public:
  virtual void update(u32 row, u32 col, T *e) = 0;
};
