#ifndef PLAYGROUND_OBSERVER_INTERFACE_H
#define PLAYGROUND_OBSERVER_INTERFACE_H

#include "../../game/include.h"

class Playground;
class Entity;
class MusicInstruments;
class Robot;

class PlaygroundObserverInterface {
public:
  virtual void clearPlayground() = 0;
  virtual void updatePlaygroundMusic(u32 row, u32 col,
                                     const MusicInstruments *mi = nullptr) = 0;
  virtual void updatePlaygroundRobot(u32 row, u32 col,
                                     const Robot *r = nullptr) = 0;
  virtual void updateDamagePosition(u32 col) = 0;
  virtual void notifyEndGame() = 0;

  virtual ~PlaygroundObserverInterface() = default;
};

#endif
