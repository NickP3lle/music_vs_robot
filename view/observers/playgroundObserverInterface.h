#ifndef PLAYGROUND_OBSERVER_INTERFACE_H
#define PLAYGROUND_OBSERVER_INTERFACE_H

class Playground;
class Entity;

class PlaygroundObserverInterface {
  public:
    virtual void updatePlayground(Entity *entity = 0) = 0;
    virtual void updatePlayground(int row, int col, Entity *entity = 0) = 0;

    virtual ~PlaygroundObserverInterface() = default;
};

#endif