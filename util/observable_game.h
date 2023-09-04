#pragma once
#include "deque.h"
#include "observer_game.h"

class ObservableGameInterface {
private:
  deque<ObserverGameInterface *> obs;

public:
  void addObserver(ObserverGameInterface *observer);
  void removeObserver(ObserverGameInterface *observer);
  void notifyClearGame() const;
  void notifyGameOver() const;
};
