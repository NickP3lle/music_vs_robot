#pragma once
#include "include.h"

class Damage : public AcceptGUI, public Cloneable {
public:
  virtual u32 getDamage() const = 0;
};

class DamageBullet : public Damage {
private:
  u32 damage;

public:
  DamageBullet(u32 damage);
  u32 getDamage() const override;
  void accept(VisitorGUI *visitor) const override;
  DamageBullet *clone() const override;
};

class DamageSlow : public Damage {
private:
  u32 damage;
  u32 slow;

public:
  DamageSlow(u32 damage, u32 slow);
  u32 getDamage() const override;
  bool getSlow();
  void accept(VisitorGUI *visitor) const override;
  DamageSlow *clone() const override;
};

class DamageWave : public Damage {
private:
  u32 wave;
  u32 persistance;

public:
  DamageWave(u32 wave);
  u32 getDamage() const override;
  bool oneWave();
  void accept(VisitorGUI *visitor) const override;
  DamageWave *clone() const override;
};

class DamageRobot : public Damage {
private:
  u32 damage;

public:
  DamageRobot(u32 damage);
  u32 getDamage() const override;
  void accept(VisitorGUI *visitor) const override;
  DamageRobot *clone() const override;
};
