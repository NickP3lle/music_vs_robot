#pragma once
#include "entity.h"

class Enemy : public EntityAbstract {
private:
  u32 h, a, s, v;

public:
  Enemy(u32, u32, bool = false, bool = false);

  u32 &getHealth() override final;
  DamageEnemy *attack() const override final;
  virtual u32 move() const;

  void accept(VisitorInterface *) const override;
  Enemy *clone() const override;
};

class EnemyDefense : public Enemy {
public:
  EnemyDefense(u32, u32);
  bool sufferDamage(DamageAbstract &) override;
  void accept(VisitorInterface *) const override;
  EnemyDefense *clone() const override;
};

class EnemyBig : public Enemy {
public:
  EnemyBig(u32, u32);
  u32 move() const override;
  void accept(VisitorInterface *) const override;
  EnemyBig *clone() const override;
};
