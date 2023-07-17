#pragma once
#include "../include.h"

class DamageAbstract : public AcceptGUI, public Cloneable {
  u32 d;

public:
  DamageAbstract(u32 damage);
  virtual u32 &getDamage();
};

class DamageBullet : public DamageAbstract {
private:
public:
  DamageBullet(u32 damage);
  void accept(VisitorGUI *visitor) const override;
  DamageBullet *clone() const override;
};

class DamageSlow : public DamageAbstract {
private:
  u32 slow;

public:
  DamageSlow(u32 damage, u32 slow);
  bool getSlow();
  void accept(VisitorGUI *visitor) const override;
  DamageSlow *clone() const override;
};

class DamageWave : public DamageAbstract {
private:
  u32 persistance;

public:
  DamageWave(u32 wave);
  bool oneWave();
  void accept(VisitorGUI *visitor) const override;
  DamageWave *clone() const override;
};

class DamageEnemy : public DamageAbstract {
private:
public:
  DamageEnemy(u32 damage);
  void accept(VisitorGUI *visitor) const override;
  DamageEnemy *clone() const override;
};
