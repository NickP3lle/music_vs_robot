#include "test_enemy.h"
bool MockVisitor::visitedEnemy = false;
bool MockVisitor::visitedEnemyDefense = false;
bool MockVisitor::visitedEnemyBig = false;

bool Test_Enemy_attack() {
  Enemy enemy(1, 10, false, false);
  DamageEnemy *damage = enemy.attack();
  bool testPassed =
      (damage != nullptr) && (damage->damage() >= 1 && damage->damage() <= 10);
  delete damage;
  return testPassed;
}

bool Test_Enemy_move() {
  Enemy enemy(1, 10, false, false);
  u32 speed = enemy.move();
  return (speed >= 1 && speed <= 10);
}

bool Test_Enemy_accept() {
  MockVisitor::visitedEnemy = false;
  MockVisitor::visitedEnemyDefense = false;
  MockVisitor::visitedEnemyBig = false;

  MockVisitor visitor;
  Enemy enemy(1, 10, false, false);
  enemy.accept(&visitor);
  bool testPassed = (visitor.visitedEnemy && !visitor.visitedEnemyDefense &&
                     !visitor.visitedEnemyBig);

  EnemyDefense enemyDefense(1, 10);
  enemyDefense.accept(&visitor);
  testPassed &= (visitor.visitedEnemy && visitor.visitedEnemyDefense &&
                 !visitor.visitedEnemyBig);

  EnemyBig enemyBig(1, 10);
  enemyBig.accept(&visitor);
  testPassed &= (visitor.visitedEnemy && visitor.visitedEnemyDefense &&
                 visitor.visitedEnemyBig);

  MockVisitor::visitedEnemy = false;
  MockVisitor::visitedEnemyDefense = false;
  MockVisitor::visitedEnemyBig = false;

  return testPassed;
}

bool Test_EnemyDefense_sufferDamage() {
  EnemyDefense enemyDefense(90, 100);
  DamagePlayer damage(50, 0, 0);

  bool isBroken = enemyDefense.sufferDamage(damage);
  bool testPassed = (!isBroken && damage.damage() == 0);

  return testPassed;
}

bool Test_EnemyBig_move() {
  EnemyBig enemyBig(1, 10);
  u32 speed = enemyBig.move();
  return (speed >= 1 && speed <= 10 && speed == enemyBig.Enemy::move() / 2);
}
