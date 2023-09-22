#include "../../entity/enemy.h"

class MockVisitor : public VisitorInterface {
  void visitDamageBullet() override{};
  void visitDamageSlow() override{};
  void visitDamageWave() override{};

  void visitSample() override{};
  void visitThreeColumn() override{};
  void visitDoubleLife() override{};
  void visitThreeRow() override{};
  void visitSlowDown() override{};

  void visitToolWeapon() override{};
  void visitToolArmor() override{};
  void visitToolBoots() override{};
  void visitToolRing() override{};

public:
  static bool visitedEnemy;
  static bool visitedEnemyDefense;
  static bool visitedEnemyBig;

  void visitEnemy() override { visitedEnemy = true; }
  void visitEnemyDefense() override { visitedEnemyDefense = true; }
  void visitEnemyBig() override { visitedEnemyBig = true; }
};

bool Test_Enemy_attack();
bool Test_Enemy_move();
bool Test_Enemy_accept();

bool Test_EnemyDefense_sufferDamage();

bool Test_EnemyBig_move();
