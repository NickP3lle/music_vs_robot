#pragma once

class ObserverGameInterface {
public:
  virtual void clearGame() = 0;
  virtual void gameOver() = 0;
  virtual ~ObserverGameInterface() = default;
};
