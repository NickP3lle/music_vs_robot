#pragma once
#include "../include.h"

class DamageAbstract : public VisitableInterface, public CloneableInterface {
  u32 d;

public:
  DamageAbstract(u32 damage);
  u32 &getDamage();
  virtual bool getSlow();
};

class DamageBullet : public DamageAbstract {
private:
public:
  DamageBullet(u32 damage);
  void accept(VisitorInterface *visitor) const override;
  DamageBullet *clone() const override;
};

class DamageSlow : public DamageAbstract {
private:
  u32 slow;

public:
  DamageSlow(u32 damage, u32 slow);
  bool getSlow() override;
  void accept(VisitorInterface *visitor) const override;
  DamageSlow *clone() const override;
};

class DamageWave : public DamageAbstract {
private:
  u32 persistance;

public:
  DamageWave(u32 wave);
  bool oneWave();
  void accept(VisitorInterface *visitor) const override;
  DamageWave *clone() const override;
};

class DamageEnemy : public DamageAbstract {
private:
public:
  DamageEnemy(u32 damage);
  void accept(VisitorInterface *visitor) const override;
  DamageEnemy *clone() const override;
};
