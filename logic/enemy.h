#pragma once

#include "entity.h"

class Enemy : public Entity {
private:
  u32 a, s, v;

public:
  Enemy(u32, u32, bool = false, bool = false);

  bool sufferDamage(Damage *) override;
  DamageEnemy *attack() const override final;
  virtual u32 move() const;

  void accept(VisitorGUI *) const override;
  Enemy *clone() const override;
};

class EnemyDefense : public Enemy {
public:
  EnemyDefense(u32, u32);
  bool sufferDamage(Damage *) override;
  void accept(VisitorGUI *) const override;
  EnemyDefense *clone() const override;
};

class EnemyBig : public Enemy {
public:
  EnemyBig(u32, u32);
  u32 move() const override;
  void accept(VisitorGUI *) const override;
  EnemyBig *clone() const override;
};
