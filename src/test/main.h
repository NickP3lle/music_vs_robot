#ifndef MAIN_H
#define MAIN_H
#include "../cash.h"
#include "../entity.h"
#include "../playground.h"

bool TestCashGetInstance();
bool TestCashAdd();
bool TestCashSub();

bool TestEntityInit();
bool TestEntityTakeDamage();
bool TestEntityUpdateHealth();
bool TestEntityUpdatePower();

class TestPlay : public Playground {
private:
  static Playground *get() {
    cleanUp();
    return getInstance();
  }

  static Playground *Get() { return getInstance(); }

public:
  static bool CleanUp() {
    for (u32 i = 0; i < 10; i++) {
      getInstance();
      cleanUp();
    }
    return true;
  }
  static bool InsertEnemy();
  static bool InsertPlayer();
  static bool Lose();
  static bool PlayerAttack();
  static bool MoveRobots();
};

#endif
