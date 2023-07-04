#ifndef PLAYGROUND_OBSERVER_INTERFACE_H
#define PLAYGROUND_OBSERVER_INTERFACE_H

class Playground;
class Entity;
class MusicInstruments;
class Robot;

class PlaygroundObserverInterface {
  public:
    virtual void updatePlayground(int row, int col, Entity *entity = nullptr) = 0;
    virtual void updatePlaygroundMusic(int row, int col, MusicInstruments *mi = nullptr) = 0;
    virtual void updatePlaygroundRobot(int row, int col, Robot *r = nullptr) = 0;

    virtual ~PlaygroundObserverInterface() = default;
};

#endif