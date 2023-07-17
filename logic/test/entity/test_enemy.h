#include "../../entity/enemy.h"

class MockVisitor : public VisitorGUI {
  void visitDamageBullet() const override{};
  void visitDamageSlow() const override{};
  void visitDamageWave() const override{};
  void visitDamageEnemy() const override{};

  void visitSample() const override{};
  void visitThreeColumn() const override{};
  void visitDoubleLife() const override{};
  void visitThreeRow() const override{};
  void visitSlowDown() const override{};

  void visitToolWeapon() const override{};
  void visitToolArmor() const override{};
  void visitToolBoots() const override{};
  void visitToolRing() const override{};

public:
  static bool visitedEnemy;
  static bool visitedEnemyDefense;
  static bool visitedEnemyBig;

  void visitEnemy() const override { visitedEnemy = true; }
  void visitEnemyDefense() const override { visitedEnemyDefense = true; }
  void visitEnemyBig() const override { visitedEnemyBig = true; }
};

bool Test_Enemy_attack();
bool Test_Enemy_move();
bool Test_Enemy_accept();

bool Test_EnemyDefense_sufferDamage();

bool Test_EnemyBig_move();
