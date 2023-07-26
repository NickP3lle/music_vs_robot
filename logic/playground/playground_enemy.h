#pragma once
#include "../entity/enemywtool.h"
#include "../include.h"
#include "timer.h"

class PlaygroundPlayer;

class PlaygroundEnemy : public PlaygroundObservableInterface<Enemy> {
private:
  deque<EnemyWTool> enemy[ROWS][COLS * FRAMES];

  void insert(u32 r, u32 c, EnemyWTool &e);
  u32 nearestPlayer(u32 r, u32 c, PlaygroundPlayer *pp);
  bool isSlow(u32 r, u32 c);

public:
  void insert();
  bool remove(u32 row, u32 col, EnemyWTool &e);
  bool isEmpty(u32 row, u32 col) const;
  void cleanUp();
  deque<EnemyWTool *> get(u32 row, u32 col);
  deque<const EnemyWTool *> get(u32 row, u32 col) const;
  void attack(PlaygroundPlayer *) const;
  bool move(PlaygroundPlayer *pp);

  void notifyObservers(u32 row, u32 col) const override;
};
