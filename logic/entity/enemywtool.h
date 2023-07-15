#pragma once
#include "enemy.h"
#include "entity.h"
#include "tool.h"

class EnemyWTool : public EntityAbstract {
private:
  ptr<Enemy> e;
  ptr<Tool> t;

  u32 &getHealth() override;

  // this make EnemyWTool a factory
  static Enemy *getEnemy(u32 min, u32 max);
  static Tool *getTool(u32 min, u32 max);

public:
  EnemyWTool(Enemy *, Tool *);
  EnemyWTool(u32 min, u32 max);

  void accept(VisitorGUI *) const override;
  EnemyWTool *clone() const override;

  bool sufferDamage(DamageAbstract *) override;
  DamageAbstract *attack() const override;

  u32 move() const;
};
