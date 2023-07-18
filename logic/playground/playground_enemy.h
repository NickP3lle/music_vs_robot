#pragma once
#include "../entity/enemywtool.h"
#include "../include.h"
#include "timer.h"

class PlaygroundPlayer;

class PlaygroundEnemy : public ObservablePlayground<Enemy> {
private:
  deque<EnemyWTool> enemy[ROWS][COLS * FRAMES];
  static PlaygroundEnemy *instance;
  PlaygroundEnemy() = default;

  static void insert(u32 r, u32 c, EnemyWTool &e);
  static u32 nearestPlayer(u32 r, u32 c);
  static bool isSlow(u32 r, u32 c);

public:
  static PlaygroundEnemy *getInstance();
  void insert();
  bool remove(u32 row, u32 col, EnemyWTool &e);
  bool isEmpty(u32 row, u32 col) const;
  void cleanUp();
  deque<EnemyWTool *> get(u32 row, u32 col);
  deque<const EnemyWTool *> get(u32 row, u32 col) const;
  void attack(PlaygroundPlayer *) const;
  bool move();

  void notifyObservers(u32 row, u32 col) const override;
};
