#pragma once
#include "../playground/cash.h"
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
  EnemyWTool(Enemy * = nullptr, Tool * = nullptr);
  EnemyWTool(u32 min, u32 max);

  void accept(VisitorInterface *) const override;
  EnemyWTool *clone() const override;

  bool sufferDamage(DamageAbstract &) override;
  DamageEnemy *attack() const override;
  bool operator==(const EnemyWTool &) const;

  u32 move() const;
};
