#pragma once
#include "../entity/enemywtool.h"
#include "../include.h"
#include "timer.h"

class PlaygroundPlayer;
class PlaygroundDamage;

class PlaygroundEnemy : public ObservablePlaygroundInterface<EnemyWTool> {
private:
  deque<EnemyWTool> enemy[ROWS][COLS * FRAMES];

  void insert(u32 r, u32 c, const EnemyWTool &e);
  u32 nearestPlayer(u32 r, u32 c, const PlaygroundPlayer &pp);
  deque<const EnemyWTool *> getAttack(u32 row, u32 col) const;

public:
  void insert();
  bool remove(u32 row, u32 col, const EnemyWTool &e);
  bool isEmpty(u32 row, u32 col) const;
  void cleanUp();
  deque<EnemyWTool *> get(u32 row, u32 col);
  deque<const EnemyWTool *> get(u32 row, u32 col) const;
  void attack(PlaygroundPlayer &) const;
  bool move(const PlaygroundPlayer &pp, PlaygroundDamage &pd);

  void notifyObservers(u32 row, u32 col) const override;
};
