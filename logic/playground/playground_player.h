#pragma once
#include "../entity/player.h"
#include "../include.h"
#include "playground_damage.h"

class PlaygroundPlayer : public ObservablePlayground<PlayerAbstract> {
private:
  ptr<PlayerAbstract> player[ROWS][COLS - 1];
  static PlaygroundPlayer *instance;
  PlaygroundPlayer() = default;

public:
  static PlaygroundPlayer *getInstance();
  bool insert(u32 row, u32 col, PlayerAbstract *player);
  bool remove(u32 row, u32 col);
  bool isEmpty(u32 row, u32 col) const;
  void cleanUp();
  bool levelUp(u32 row, u32 col) const;
  PlayerAbstract *get(u32 row, u32 col);
  const PlayerAbstract *get(u32 row, u32 col) const;
  void attack(PlaygroundDamage *) const;

  void notifyObservers(u32 row, u32 col) const override;
};
