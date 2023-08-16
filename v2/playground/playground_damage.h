#pragma once
#include "../entity/damage.h"
#include "../include.h"
#include "playground_enemy.h"

class PlaygroundDamage : public PlaygroundObservableInterface<DamageAbstract> {
private:
  ptr<DamagePlayer> damage[ROWS][COLS];

public:
  void clear();
  void insert(u32 row, u32 col, DamagePlayer &d);
  bool remove(u32 row, u32 col);
  bool isEmpty(u32 row, u32 col) const;
  DamagePlayer &get(u32 row, u32 col);
  const DamagePlayer &get(u32 row, u32 col) const;
  void attack(PlaygroundEnemy &);
  void move(const PlaygroundEnemy &pe);
  bool isSlow(u32 row, u32 col);

  void notifyObservers(u32 row, u32 col) const override;
};
