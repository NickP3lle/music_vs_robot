#pragma once
#include "../entity/damage.h"
#include "../include.h"
#include "playground_enemy.h"

class PlaygroundDamage : public ObservablePlayground<DamageAbstract> {
private:
  ptr<DamageAbstract> damage[ROWS][COLS];
  static PlaygroundDamage *instance;
  PlaygroundDamage() = default;

public:
  static PlaygroundDamage *getInstance();
  void insert(u32 row, u32 col, DamageAbstract *d);
  bool remove(u32 row, u32 col);
  bool isEmpty(u32 row, u32 col) const;
  void cleanUp();
  DamageAbstract *get(u32 row, u32 col);
  const DamageAbstract *get(u32 row, u32 col) const;
  void attack(PlaygroundEnemy *);
  void move();
  bool isSlow(u32 row, u32 col);

  void notifyObservers(u32 row, u32 col) const override;
};
