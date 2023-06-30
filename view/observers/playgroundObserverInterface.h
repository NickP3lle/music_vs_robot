#ifndef PLAYGROUND_OBSERVER_INTERFACE_H
#define PLAYGROUND_OBSERVER_INTERFACE_H

class Playground;

class PlaygroundObserverInterface {
  public:
    virtual void updatePlayground() = 0;
    virtual void updatePlayground(int row, int col) = 0;

    virtual ~PlaygroundObserverInterface() = default;
};

#endif