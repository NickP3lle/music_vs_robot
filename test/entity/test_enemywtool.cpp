#include "test_enemywtool.h"

bool Test_EnemyWTool_attack() {
  Enemy *enemy = new Enemy(10, 20);
  Tool *tool = new ToolWeapon(5, 15);

  EnemyWTool enemyWTool(enemy, tool);

  DamageEnemy *damage = enemyWTool.attack();

  DamageEnemy *expectedDamage = enemy->attack();
  *expectedDamage = *expectedDamage + tool->attack();

  bool testPassed =
      (damage != nullptr) && damage->damage() == expectedDamage->damage();

  delete enemy;
  delete tool;
  delete damage;
  delete expectedDamage;

  return testPassed;
}

bool Test_EnemyWTool_move() {
  Enemy *enemy = new Enemy(10, 20);
  Tool *tool = new ToolWeapon(5, 15);
  EnemyWTool enemyWTool(enemy, tool);

  u32 totalMove = enemyWTool.move();

  bool testPassed = (totalMove == (enemy->move() + tool->move()));

  delete enemy;
  delete tool;

  return testPassed;
}
